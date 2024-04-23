#pragma once

namespace FilippenkoLab4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	mat3 T; // матрица,в которой накапливаются все преобразования 
	// первоначально- единичная матрица 
	mat3 initT; // матрица начального преобразования

	vector<model> models;

	float aspectFig, Vx, Vy;


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::Button^ btnOpen;

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->Filter = L"Текстовые файлы(*.txt)|*.txt|Все файлы(*.*)|*.*";
			this->openFileDialog->Title = L"Открыть файл";
			// 
			// btnOpen
			// 
			this->btnOpen->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnOpen->Location = System::Drawing::Point(1181, 36);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(106, 34);
			this->btnOpen->TabIndex = 0;
			this->btnOpen->Text = L"Открыть";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &MyForm::btnOpen_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1315, 643);
			this->Controls->Add(this->btnOpen);
			this->KeyPreview = true;
			this->MinimumSize = System::Drawing::Size(120, 155);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}

#pragma endregion
	private: float left = 30, right = 100, top = 20, bottom = 50; // расстояния до границ окна
		   float minX = left, maxX; //диапазон изменения координат x 
		   float minY = top, maxY; //диапазон изменения координат y 
		   float Wcx = left, Wcy; //координаты левого нижнего угла прямоугольника 
		   float Wx, Wy; //ширина и высота прямоугольника

	private: System::Void rectCalc() {
		maxX = ClientRectangle.Width - right; // диапазон изменения координат x 
		maxY = ClientRectangle.Height - bottom; // диапазон изменения координат y 
		Wcy = maxY; // координаты левого нижнего угла прямоугольника 
		Wx = maxX - left; // ширина прямоугольника 
		Wy = maxY - top; // ширина и высота прямоугольника 
	}
	private:System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::White);

		Pen^ rectPen = gcnew Pen(Color::Black, 2);
		g->DrawRectangle(rectPen, left, top, Wx, Wy);
		for (int k = 0; k < models.size(); k++) { //циклпо рисункам 
			vector<path>figure = models[k].figure; //списокломаных очередногорисунка 
			mat3 TM = T * models[k].modelM; //матрицаобщегопреобразованиярисунка 
			for (int i = 0; i < figure.size(); i++) {
				path lines = figure[i]; //lines-очереднаяломанаялиния 
				Pen^ pen = gcnew Pen(Color::FromArgb(lines.color.x, lines.color.y, lines.color.z));
				pen->Width = lines.thickness;

				vec2 start = normalize(TM * vec3(lines.vertices[0], 1.0)); //начальнаяточкапервогоотрезка 
				for (int j = 1; j < lines.vertices.size(); j++) { //циклпоконечнымточкам(отединицы) 
					vec2 end = normalize(TM * vec3(lines.vertices[j], 1.0)); //конечнаяточка 
					vec2 tmpEnd = end; //продублировали координатыточкидлябудущегоиспользования 
					if (clip(start, end, minX, minY, maxX, maxY)) { //еслиотрезок видим 
						//послеотсечения,startиend-концы видимойчастиотрезка 
						g->DrawLine(pen, start.x, start.y, end.x, end.y); //отрисовкавидимыхчастей 
					}
					start = tmpEnd; //конечнаяточканеотсеченногоотрезкастановится начальнойточкойследующего 
				}
			}
		}
	}

	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		rectCalc();
		Refresh();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		rectCalc();
	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		float Wcx = (maxX - left) / 2.f; // координаты центра 
		float Wcy = (maxY - top) / 2.f; // текущего окна
		switch (e->KeyCode) {

		case Keys::Q:
			T = translate(-Wcx, -Wcy) * T; // перенос начала координат в 
			T = rotate(0.01f) * T; // поворот на 0.01 радиан относительно нового центра 
			T = translate(Wcx, Wcy) * T; // перенос начала координат обратно 
			break;
		case Keys::E:
			T = translate(-Wcx, -Wcy) * T; // перенос начала координат в 
			T = rotate(-0.01f) * T; // поворот на 0.01 радиан относительно нового центра 
			T = translate(Wcx, Wcy) * T; // перенос начала координат обратно 
			break;
		case Keys::R:
			T = translate(-Wcx, -Wcy) * T; // перенос начала координат в 
			T = rotate(-0.05f) * T; // поворот на 0.05 радиан относительно нового центра 
			T = translate(Wcx, Wcy) * T; // перенос начала координат обратно 
			break;
		case Keys::Y:
			T = translate(-Wcx, -Wcy) * T; // перенос начала координат в 
			T = rotate(0.05f) * T; // поворот на 0.05 радиан относительно нового центра 
			T = translate(Wcx, Wcy) * T; // перенос начала координат обратно 
			break;

		case Keys::W:
			T = translate(0.f, -1.f) * T; // сдвиг вверх на один пиксел 
			break;
		case Keys::S:
			T = translate(0.f, 1.f) * T; // сдвиг вниз на один пиксел 
			break;
		case Keys::D:
			T = translate(1.f, 0.f) * T; // сдвиг вправо на один пиксел 
			break;
		case Keys::A:
			T = translate(-1.f, 0.f) * T; // сдвиг влево на один пиксел 
			break;

		case Keys::T:
			T = translate(0.f, -10.f) * T; // сдвиг вверх на один пиксел 
			break;
		case Keys::G:
			T = translate(0.f, 10.f) * T; // сдвиг вниз на один пиксел 
			break;
		case Keys::H:
			T = translate(10.f, 0.f) * T; // сдвиг вниз на один пиксел 
			break;
		case Keys::F:
			T = translate(-10.f, 0.f) * T; // сдвиг вниз на один пиксел 
			break;

		case Keys::Z:
			T = translate(-Wcx, -Wcy) * T; // перенос начала координат в 
			T = scale(1.1) * T;
			T = translate(Wcx, Wcy) * T; // сдвиг влево на один пиксел 
			break;
		case Keys::X:
			T = translate(-Wcx, -Wcy) * T; // перенос начала координат в 
			T = scale(1 / 1.1) * T;
			T = translate(Wcx, Wcy) * T; // сдвиг влево на один пиксел 
			break;

		case Keys::U:
			T = (translate(-Wcx, -Wcy)) * T;
			T = mirrorX() * T;
			T = (translate(Wcx, Wcy)) * T;
			break;
		case Keys::J:
			T = (translate(-Wcx, -Wcy)) * T;
			T = mirrorY() * T;
			T = (translate(Wcx, Wcy)) * T;
			break;


		case Keys::I:
			T = (translate(-Wcx, -Wcy)) * T;
			T = scale(1.1, 1) * T;
			T = (translate(Wcx, Wcy)) * T;
			break;
		case Keys::K:
			T = (translate(-Wcx, -Wcy)) * T;
			T = scale(1 / 1.1, 1) * T;
			T = (translate(Wcx, Wcy)) * T;
			break;
		case Keys::O:
			T = (translate(-Wcx, -Wcy)) * T;
			T = scale(1, 1.1) * T;
			T = (translate(Wcx, Wcy)) * T;
			break;
		case Keys::L:
			T = (translate(-Wcx, -Wcy)) * T;
			T = scale(1, 1 / 1.1) * T;
			T = (translate(Wcx, Wcy)) * T;
			break;



		case Keys::Escape:
			T = initT; // присвоили T единичную матрицу 
			break;


		default:
			break;
		}
		Refresh();
	}

	private: System::Void btnOpen_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			//в файловом диалоге нажата кнопка OK 
			//перезапись имени файла из open FileDialog->FileName в fileName
			wchar_t fileName[1024]; //переменная,в которой посимвольно сохраним имя файла 
			for (int i = 0; i < openFileDialog->FileName->Length; i++)
				fileName[i] = openFileDialog->FileName[i];
			fileName[openFileDialog->FileName->Length] = '\0';
			//объявление и открытие файла 
			ifstream in;
			in.open(fileName);
			if (in.is_open()) {
				//файлуспешно открыт 
				models.clear(); //очищаемимеющийсясписокрисунков 
				//временныепеременныедлячтенияизфайла 
				mat3 M = mat3(1.f); //матрицадля получениямодельнойматрицы 
				mat3 initM; //матрицадля начальногопреобразованиякаждогорисунка 
				vector<mat3>transforms; //стекматриц преобразований 
				vector<path>figure; //списокломаных очередногорисунка 
				float thickness = 2; //толщинасо значениемпоумолчанию2 
				float r, g, b; //составляющие цвета 
				r = g = b = 0; //значениесоставляющихцветапоумолчанию(черный) 
				string cmd; //строкадля считыванияименикоманды 
				//непосредственно работасфайлом 
				string str; //строка,вкоторуюсчитываемстрокифайла
				getline(in, str); //считываемиз входногофайлапервуюстроку 
				while (in) { //еслиочередная строкасчитанауспешно
					//обрабатываемстроку 
					if ((str.find_first_not_of("\t\r\n") != string::npos) && (str[0] != '#')) {
						//прочитанная строканепустаинекомментарий 
						stringstream s(str); //строковыйпотокизстрокиstr 
						s >> cmd;
						if (cmd == "frame") { //размерыизображения 
							s >> Vx >> Vy; //считываемглобальныезначениеVxиVy 
							aspectFig = Vx / Vy; //обновлениесоотношениясторон 
							float aspectRect = Wx / Wy; //соотношениесторонпрямоугольника 
							//смещениецентра рисункасначаломкоординат 
							mat3 T1 = translate(-Vx / 2, -Vy / 2);
							//масштабирование остаетсяпрежним,меняетсятолько привязка 
							//коэффициентувеличенияприсохраненииисходногосоотношениясторон 
							float S = aspectFig < aspectRect ? Wy / Vy : Wx / Vx;
							mat3 S1 = scale(S, -S);
							//сдвигточки привязкиизначалакоординатв нужнуюпозицию 
							mat3 T2 = translate(Wx / 2 + Wcx, Wcy - Wy / 2);
							//ВinitTсовмещаемэтитрипреобразования(справаналево) 
							initT = T2 * (S1 * T1);
							T = initT;
						}
						else if (cmd == "color") { //цветлинии 
							s >> r >> g >> b; //считываем трисоставляющиецвета 
						}
						else if (cmd == "thickness") { //толщиналинии 
							s >> thickness; //считываемзначениетолщины 
						}
						else if (cmd == "path") { //наборточек 
							vector<vec2>vertices; //списокточекломаной 
							int N; //количество точек 
							s >> N;
							string str1; //дополнительная строкадлячтенияизфайла
							while (N > 0) { //поканевсе точкисчитали 
								getline(in, str1); //считываемв str1извходногофайлаочередную строку 
								//таккак файлкорректный,тонаконец файлапроверятьненужно 
								if ((str1.find_first_not_of("\t\r\n") != string::npos) && (str1[0] != '#')) {
									//прочитаннаястроканепустаинекомментарий 
									//значитвнейпаракоординат 
									float x, y; //переменныедля считывания 
									stringstream s1(str1); //ещеодинстроковыйпотокизстрокиstr1 
									s1 >> x >> y;
									vertices.push_back(vec2(x, y)); //добавляемточку всписок 
									N--; //уменьшаемсчетчикпослеуспешногосчитыванияточки 
								}
							}
							//всеточкисчитаны,генерируемломаную(path)и кладемеевсписокfigure 
							figure.push_back(path(vertices, vec3(r, g, b), thickness));
						}

						else if (cmd == "model") { //началоописанияновогорисунка
							float mVcx, mVcy, mVx, mVy; //параметрыкомандыmodel 
							s >> mVcx >> mVcy >> mVx >> mVy; //считываемзначенияпеременных 
							float S = mVx / mVy < 1 ? 2.f / mVy : 2.f / mVx;
							//сдвигточки привязкиизначалакоординатв нужнуюпозицию 
							//послекоторого проводиммасштабирование 
							initM = scale(S) * translate(-mVcx, -mVcy);
							figure.clear();
						}
						else if (cmd == "figure") { //формирование новоймодели 
							models.push_back(model(figure, M * initM));
						}
						else if (cmd == "translate") { //перенос 
							float Tx, Ty; //параметрыпреобразованияпереноса 
							s >> Tx >> Ty; //считываемпараметры 
							M = translate(Tx, Ty) * M; //добавляемпереноскобщемупреобразованию 
						}
						else if (cmd == "scale") { //масштабирование 
							float S; //параметрмасштабирования 
							s >> S; //считываемпараметр 
							M = scale(S) * M; //добавляеммасштабированиекобщемупреобразованию 
						}
						else if (cmd == "rotate") { //поворот 
							float theta; //уголповоротавградусах 
							s >> theta; //считываемпараметр 
							M = rotate(-theta / 180.f * Math::PI) * M; //добавляемповороткобщемупреобразованию 
						}
						else if (cmd == "pushTransform") { //сохранениематрицывстек 
							transforms.push_back(M); //сохраняемматрицувстек 
						}
						else if (cmd == "popTransform") { //откаткматрицеизстека 
							M = transforms.back(); //получаемверхний элементстека 
							transforms.pop_back(); //выкидываемматрицу изстека 
						}
					}
					//считываемочереднуюстроку 
					getline(in, str);
				}
				Refresh();
			}
		}
	}
	};

}
