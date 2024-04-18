#pragma once

namespace FilippenkoLab4 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace std;


    /// <summary>
    /// ������ ��� MyForm
    /// </summary>

    float lines[] = {
        // ������
        5.0f, 0.0f, 2.0f, 0.f, // �� ����� 1 ���� ����� ������ ���� (1) � ����� ���� ���� (2)
        2.0f, 0.f, 4.f, 2.f, // �� ������ ���� ���� ����� (2) �� 45 �������� (3)
        4.f, 2.f, 4.f, 10.f, // ����� 45 �������� (3) ����� �� �������� (4)
        4.f, 10.f, 3.f, 12.f, // �� ���� �������� (����� ����� ���� ������) (4) �� �������� �������� ����� 45 (5)
        3.f, 12.f, 4.f, 14.f, // �� ����� �������� �������� (5) �� 45 �������� ����� ������ (6)
        4.f, 14.f, 5.f, 15.f, // �� (6) � ���� �������� (7)

        // ������� 7-8-9-10-11
        5.f, 15.f, 5.f, 14.f,
        5.f, 14.f, 6.f, 14.f,
        6.f, 14.f, 6.f, 15.f,
        6.f, 15.f, 5.f, 15.f,
        //

        // triangle left 12-13-14
        // 12 ����� = 6.f, 14.f
        6.f, 13.f, 7.f, 13.f, // 12-13
        7.f, 13.f, 7.f, 14.f, // 13-14
        7.f, 14.f, 6.f, 13.f, // 14-12
        //

        //������ ���
        5.f, 15.f, 6.f, 20.f, // 11-15 �� �������� ����� (������ ���) �� ������������ ��� 45 �� ��� �������

        //����������� ��� ������� 
        // 15 ����� = 6.f, 20.f
        6.f, 20.f, 7.f, 20.f,
        7.f, 20.f, 6.f, 21.f,

        //������ ������
        6.f, 20.f, 6.f, 23.25f, // �� 15 � �� 18 (�� �����)

        // 18 = 6.f, 23.25f,
        // ������ ��� ������� ����� 19-20-21-22
        6.f, 22.f, 7.f, 21.f,
        7.f, 21.f, 8.f, 22.f,
        8.f, 22.f, 7.f, 23.f,
        7.f, 23.f, 6.f, 22.f,

        // ������ 
        6.f, 23.25f, 8.f, 24.f, // 18-23
        6.f, 23.25f, 5.f, 23.f, // 18-24
        5.f, 23.f, 3.f, 24.f, // 24-25
        3.f, 24.f, 3.f, 25.f, // 25-26
        3.f, 25.f, 5.f, 26.f, // 26-27

        //���� ����� 27-28-29
        // 27 = 5.f, 26.f,

        5.f, 26.f, 6.f, 26.f, //27-28
        6.f, 26.f, 6.f, 27.f, //28-29
        6.f, 27.f, 5.f, 26.f, //29-27

        // ���� ������ 30-31-32
        7.f, 26.f, 8.f, 26.f, //30-31
        8.f, 26.f, 8.f, 27.f, //31-32
        8.f, 27.f, 7.f, 26.f, //32-30

        // ���� ������
        5.f, 26.f, 5.f, 27.f, //27-33

        //��� ����� 33-34-35-36-33
        5.f, 27.f, 3.f, 26.f, //33-34
        3.f, 26.f, 2.f, 28.f, //34-35
        2.f, 28.f, 4.f, 28.f, //35-36
        4.f, 28.f, 5.f, 27.f, //36-33

        // ���� ������
        5.f, 27.f, 6.f, 28.f, //33-37
        6.f, 28.f, 8.f, 28.f, //37-38
        8.f, 28.f, 9.f, 27.f, //38-39

        // 39-40-41-42-43 - ��� ������
        9.f, 27.f, 10.f, 28.f, //39-40
        10.f, 28.f, 12.f, 28.f, //40-41
        12.f, 28.f, 12.f, 27.f, //41-42
        12.f, 27.f, 10.f, 26.f, //42-43
        10.f, 26.f, 11.f, 25.f, //43-44
        11.f, 25.f, 9.f, 23.f, //44-45

        // ��� �� ����� ����
        9.f, 23.f, 9.f, 15.f, //45-46

        //������ �� ��� ������

        // 47-48-49-50
        9.f, 22.f, 8.f, 21.f, //47-48
        8.f, 21.f, 8.f, 20.f, //48-49
        8.f, 20.f, 9.f, 19.f, //49-50

        //51-52-53
        9.f, 18.f, 8.f, 19.f, //51-52
        8.f, 19.f, 7.f, 18.f, //52-53
        7.f, 18.f, 9.f, 18.f, //53-51

        //54-55-46
        9.f, 17.f, 7.f, 15.f, //54-55
        7.f, 15.f, 9.f, 15.f, //55-46

        //56-57-58-56
        6.f, 17.f, 6.f, 16.f, //56-57
        6.f, 16.f, 7.f, 16.f, //57-58
        7.f, 16.f, 6.f, 17.f, //58-56


        //��������
            9.f, 15.f, 12.f, 13.f, //46-59
            12.f, 13.f, 14.f, 12.f, //59-60
            14.f, 12.f, 15.f, 11.f, //60-61
            15.f, 11.f, 16.f, 9.f, //61-62
            16.f, 9.f, 17.f, 10.f, //62-63
            17.f, 10.f, 17.f, 13.f, //63-64
            17.f, 13.f, 18.f, 14.f, //64-65
            18.f, 14.f, 18.f, 15.f, //65-66
            18.f, 15.f, 20.f, 16.f, //66-67
            20.f, 16.f, 19.f, 14.f, //67-68
            19.f, 14.f, 18.f, 14.f, //68-65
            17.f, 13.f, 18.f, 9.f, //64-69
            18.f, 9.f, 16.f, 8.f, //69-70
            16.f, 8.f, 15.f, 5.f, //70-71
            15.f, 5.f, 16.f, 3.f, //71-72
            16.f, 3.f, 15.f, 1.f, //72-73
            15.f, 1.f, 16.f, 0.f, //73-74
            16.f, 0.f, 12.f, 0.f, //74-75
            13.f, 0.f, 11.f, 0.f, //75-76
            12.f, 0.f, 13.f, 2.f, //75-78
            11.f, 0.f, 12.f, 2.f, //76-77
            12.f, 2.f, 13.f, 2.f, //77-78
            13.f, 2.f, 14.f, 3.f, //78-82
            14.f, 3.f, 12.f, 7.4f, //82-83
            13.f, 2.f, 14.f, 2.f, //78-79
            14.f, 2.f, 15.f, 3.f, //79-80
            15.f, 3.f, 13.f, 7.f, //80-81


            13.f, 7.f, 14.f, 10.f, //81-84

            //������� 84-60-85-86-84
            14.f, 10.f, 14.f, 12.f, //84-60
            14.f, 12.f, 13.f, 12.f, //60-85
            13.f, 12.f, 13.f, 10.f, //85-86
            13.f, 10.f, 14.f, 10.f, //86-84

            13.f, 7.f, 8.f, 9.f, //81-87
            8.f, 9.f, 7.f, 2.f, //87-88
            7.f, 2.f, 8.f, 0.f, //88-89
            8.f, 0.f, 5.f, 0.f, //89-1
            5.f, 0.f, 6.f, 2.f, //1-90
            6.f, 2.f, 6.f, 10.f, //90-91
            6.f, 10.f, 7.f, 10.f, //91-92
            7.f, 10.f, 8.f, 9.f, //92-87
            6.f, 10.f, 5.f, 11.f, //91-93
            6.f, 10.f, 5.f, 2.f, //91-94
            5.f, 2.f, 5.f, 0.f, //94-1

            //���� 95-96-97-98-95
            9.f, 10.f, 8.f, 11.f, //95-96
            8.f, 11.f, 9.f, 12.f, //96-97
            9.f, 12.f, 10.f, 11.f, //97-98
            10.f, 11.f, 9.f, 10.f, //98-95

            //������� 62-70-99-100-62
            16.f, 9.f, 16.f, 8.f, //62-70
            16.f, 8.f, 15.f, 8.f, //62-99
            15.f, 8.f, 15.f, 9.f, //99-100
            15.f, 9.f, 16.f, 9.f, //100-62

            //103-101-102-103
            12.f, 10.f, 11.f, 9.f, //103-101
            11.f, 9.f, 11.f, 10.f, //101-102
            11.f, 10.f, 12.f, 10.f, //102-103


            //59-104-105-106-107-108-59
            12.f, 13.f, 12.f, 11.f, //59-104
            12.f, 11.f, 11.f, 11.f, //104-105
            11.f, 11.f, 11.f, 12.f, //105-106
            11.f, 12.f, 10.f, 12.f, //106-107
            10.f, 12.f, 10.f, 13.f, //107-108
            10.f, 13.f, 12.f, 13.f, //108-59


            //109-110-111-112-109
            9.f, 14.f, 9.f, 13.f, //109-110
            9.f, 13.f, 8.f, 13.f, //110-111
            8.f, 13.f, 8.f, 14.f, //111-112
            8.f, 14.f, 9.f, 14.f, //112-109

    }; float lines_2[] = {
            // ������
            0.5f,3.f,1.f,4.5f, // �� ����� ���� ����� �� ���
            1.f,4.5f,0.5f,6.f, // ����� ��� ����� ����� �����
            0.5f,6.f,0.5f, 7.5f, // ����� ��� �����
            0.5f, 7.5f,1.f,8.f, // ����� ��� ���� �����
            1.f,8.f,1.5f,8.f, // ����� ��� ���� ��������
            1.5f,8.f,2.f,7.5f, // ����� ��� ���� ������
            2.f,7.5f,1.5f, 6.f, // ����� ��� ������ ������ ����
            1.5f, 6.f,1.5f,4.5f, // ����� ��� ������ �� �������
            1.5f,4.5f,3.f,4.5f, // �������
            3.f,4.5f,3.f,6.f, // ������ ��� ����� ����� �����
            3.f,6.f,2.5f,7.5f, // ������ ��� �����
            2.5f,7.5f,3.f,8.f, // ������ ��� ���� �����
            3.f,8.f,3.5f,8.f, // ������ ��� ���� ��������
            3.5f,8.f,4.f,7.5f, // ������ ��� ���� ������
            4.f,7.5f,4.f,6.f, // ������ ��� ������ ����
            4.f,6.f,3.5f,4.5f, // ������ ��� ������
            3.5f,4.5f,4.f,3.f, // �� ������� ��� ���� �� ����
            4.f,3.f,3.5f,1.5f, // ������ �����
            3.5f,1.5f,2.5f,1.f, // ���������� ������
            2.5f,1.f,2.f,1.f, // ���������� �����
            2.f,1.f,1.f,1.5f, // ���������� �����
            1.f,1.5f,0.5f,3.f, // ����� �����
            // ��������
            4.f,3.f,5.5f,3.5f, // ����� �� ������ ������
            5.5f,3.5f,7.f,3.5f, // ����� ����
            7.f,3.5f,7.5f,2.5f, // ����� ������ �� ������
            7.5f,2.5f,8.f,2.5f, // ����� ������
            8.f,2.5f,8.f,2.f, // ����� ������
            8.f,2.f,7.5f,2.f, // ����� ��� ������ ������
            7.5f,2.f,7.5f,0.5f, // ������ ���� ������ ������ ����
            7.5f,0.5f,6.5f,0.5f, // ������ ���� ���
            6.5f,0.5f,6.5f,1.f, // ������ ���� �����
            6.5f,1.f,6.f,1.f, // ����� ������ ���
            6.f,1.f,6.f,0.5f, // ����� ������ ���� ������
            6.f,0.5f,5.f,0.5f, // ����� ������ ���� ���
            5.f,0.5f,5.f,1.f, // ����� ������ ���� �����
            5.f,1.f,4.f,1.f, // ����� ������� � ��������� ������
            4.f,1.f,4.f,0.5f, // ������ �������� ���� ������
            4.f,0.5f,3.f,0.5f, // ������ �������� ���� ���
            3.f,0.5f,3.f,1.f, // ������ �������� ���� �����
            3.f,1.f,2.5f,1.f, // ����� �������� ���
            2.5f,1.f,2.5f,0.5f, // �������� ���� ������
            2.5f,0.5f,1.5f,0.5f, // �������� ���� ���
            1.5f,0.5f,1.5f,1.25f, // �������� ���� �����
            // ����� ����
            1.5f,3.5f,1.5f,3.f, // ����� ���� ����� ������ ����
            1.5f,3.f,2.f,3.f, // ����� ���� ���
            2.f, 3.f,2.f,3.5f, // ����� ���� ������
            2.f,3.5f,1.5f,3.5f, // ����� ���� ����
            // ������ ����
            2.5f,3.5f,2.5f,3.f, // ������ ���� �����
            2.5f,3.f,3.f, 3.f, // ������ ���� �����
            3.f,3.f,3.f,3.5f, // ������ ���� ������
            3.f,3.5f,2.5f,3.5f, // ������ ���� ������
            // ����� ��������
            1.f,5.5f,1.f,7.f, // ����� ����� ��������
            3.5f,5.5f,3.5f,7.f, // ������ ����� ��������
            // ���
            2.f,2.5f,2.5f,2.5f, // ��� ������
            2.5f,2.5f,2.25f,2.f, // ��� ������
            2.25f,2.f,2.f,2.5f // ��� �����
    };

    float Vx; // ������ ������� �� �����������
    float Vy; // ������ ������� �� ���������
    float aspectFig; // ����������� ������ �������
    vector<model> models;
    mat3 T, T1, T2; // �������, � ������� ������������� ��� ��������������
    mat3 initT; // ������� ���������� ��������������


    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            //
            //TODO: �������� ��� ������������
            //
        }

    protected:
        /// <summary>
        /// ���������� ��� ������������ �������.
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
    private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

    protected:


    private:
        /// <summary>
        /// ������������ ���������� ������������.
        /// </summary>
        System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
        /// <summary>
        /// ��������� ����� ��� ��������� ������������ � �� ��������� 
        /// ���������� ����� ������ � ������� ��������� ����.
        /// </summary>
        void InitializeComponent(void)
        {
            this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
            this->btnOpen = (gcnew System::Windows::Forms::Button());
            this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
            this->SuspendLayout();
            // 
            // openFileDialog
            // 
            this->openFileDialog->DefaultExt = L"txt";
            this->openFileDialog->FileName = L"������� ���� ������";
            this->openFileDialog->Filter = L"��������� ����� (*.txt)|*.txt|��� ����� (*.*)|*.*";
            this->openFileDialog->Title = L"������� ����";
            // 
            // btnOpen
            // 
            this->btnOpen->Location = System::Drawing::Point(99, 111);
            this->btnOpen->Name = L"btnOpen";
            this->btnOpen->Size = System::Drawing::Size(75, 23);
            this->btnOpen->TabIndex = 0;
            this->btnOpen->Text = L"�������";
            this->btnOpen->UseVisualStyleBackColor = true;
            this->btnOpen->Click += gcnew System::EventHandler(this, &MyForm::btnOpen_Click);
            // 
            // openFileDialog1
            // 
            this->openFileDialog1->FileName = L"openFileDialog1";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(282, 253);
            this->Controls->Add(this->btnOpen);
            this->KeyPreview = true;
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
            this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
            this->ResumeLayout(false);

        }
#pragma endregion
    private: float left = 30, right = 100, top = 20, bottom = 50; // ���������� �� ������ ����
           float minX = left, maxX; // �������� ��������� ��������� x
           float minY = top, maxY; // �������� ��������� ��������� y
           float Wcx = left, Wcy; // ���������� ������ ������� ���� ��������������
           float Wx, Wy; // ������ � ������ ��������������

    private: System::Void rectCalc() {
        maxX = ClientRectangle.Width - right; // �������� ��������� ��������� x
        maxY = ClientRectangle.Height - bottom; // �������� ��������� ��������� y
        Wcy = maxY; // ���������� ������ ������� ���� ��������������
        Wx = maxX - left; // ������ ��������������
        Wy = maxY - top; // ������ � ������ ��������������
    }


    private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        Graphics ^ g = e->Graphics;
        g->Clear(Color::White);

        Pen ^ rectPen = gcnew Pen(Color::Black, 2);

        g->DrawRectangle(rectPen, left, top, Wx, Wy);


        for (int k = 0; k < models.size(); k++) { // ���� �� ��������
            vector<path> figure = models[k].figure; // ������ ������� ���������� �������
            mat3 TM = T * models[k].modelM; // ������� ������ �������������� �������

            for (int i = 0; i < figure.size(); i++) {
                path lines = figure[i]; // lines - ��������� ������� �����
                Pen^ pen = gcnew Pen(Color::FromArgb(lines.color.x, lines.color.y, lines.color.z));
                pen->Width = lines.thickness;


                vec2 start = normalize(T * vec3(lines.vertices[0], 1.0)); // ��������� ����� ������� �������


                for (int j = 1; j < lines.vertices.size(); j++) { // ���� �� �������� ������ (�� �������)

                    vec2 end = normalize(T * vec3(lines.vertices[j], 1.0)); // �������� �����
                    vec2 tmpEnd = end; // �������������� ���������� ����� ��� �������� �������������

                    if (clip(start, end, minX, minY, maxX, maxY)) { // ���� ������� �����
                        // ����� ���������, start � end - ����� ������� ����� �������
                        g->DrawLine(pen, start.x, start.y, end.x, end.y); // ��������� ������� ������
                    }
                    start = tmpEnd; // �������� ����� ������������� ������� ���������� ��������� ������ ����������
                }
            }
        }
    }
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        rectCalc();
    }

    private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

        float Wcx = (maxX + left) / 2; // ���������� ������
        float Wcy = (maxY + top) / 2; // �������� ����

        switch (e->KeyCode)
        {
        case Keys::Q:
            T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
            T = rotate(0.01f) * T; // ������� �� 0.01 ������ ������������
            T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
            break;
        case Keys::E:
            T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
            T = rotate(-0.01f) * T; // ������� �� 0.01 ������ ������������
            T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
            break;
        case Keys::Y:
            T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
            T = rotate(-0.05f) * T; // ������� �� 0.01 ������ ������������
            T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������

            break;
        case Keys::R:
            T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
            T = rotate(0.05f) * T; // ������� �� 0.01 ������ ������������
            T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
            break;

        case Keys::W:
            T = translate(0.f, -1.f) * T; // ����� ����� �� ���� ������
            break;
        case Keys::A:
            T = translate(-1.f, 0.f) * T; // ����� ����� �� ���� ������
            break;
        case Keys::S:
            T = translate(0.f, 1.f) * T; // ����� ����� �� ���� ������
            break;
        case Keys::D:
            T = translate(1.f, 0.f) * T; // ����� ����� �� ���� ������
            break;
        case Keys::T:
            T = translate(0.f, -10.f) * T; // ����� ����� �� ���� ������
            break;
        case Keys::G:
            T = translate(0.f, 10.f) * T; // ����� ����� �� ���� ������
            break;
        case Keys::F:
            T = translate(-10.f, 0.f) * T; // ����� ����� �� ���� ������
            break;
        case Keys::H:
            T = translate(10.f, 0.f) * T; // ����� ����� �� ���� ������
            break;

        case Keys::Escape:
            T = initT; // ��������� T ��������� �������
            break;
        case Keys::J:

            T = (translate(-Wcx, -Wcy)) * T;
            T = mirrorY() * T;
            T = (translate(Wcx, Wcy)) * T;
            break;
        case Keys::U:
            T = (translate(-Wcx, -Wcy)) * T;
            T = mirrorX() * T;
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
        case Keys::Z:
            T = (translate(-Wcx, -Wcy)) * T;
            T = scale(1.1) * T;
            T = (translate(Wcx, Wcy)) * T;
            break;
        case Keys::X:
            T = (translate(-Wcx, -Wcy)) * T;
            T = scale(1 / 1.1) * T;
            T = (translate(Wcx, Wcy)) * T;
            break;
        default:
            break;
        }
        Refresh();

        //switch (e->KeyCode) {
        //case Keys::Q:
        //    T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
        //    T = rotate(0.01f) * T; // ������� �� 0.01 ������ ������������
        //    // ������ ������
        //    T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
        //    break;
        //case Keys::W:
        //    T = translate(0.f, -1.f) * T; // ����� ����� �� ���� ������
        //    break;
        //case Keys::Escape:
        //    T = initT;
        //    T = mat3(1.f); // ��������� T ��������� �������
        //    break;
        //case Keys::E:
        //    T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
        //    T = rotate(-0.01f) * T; // ������� �� 0.01 ������ ������������
        //    T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
        //    break;
        //case Keys::A:
        //    T = translate(-1.f, 0.f) * T; // ����� ����� �� ���� ������
        //    break;
        //case Keys::S:
        //    T = translate(0.f, 1.f) * T; // ����� ����� �� ���� ������
        //    break;
        //case Keys::D:
        //    T = translate(1.f, 0.f) * T; // ����� ����� �� ���� ������
        //    break;

        //case Keys::Y:
        //    T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
        //    T = rotate(-0.05f) * T; // ������� �� 0.01 ������ ������������
        //    T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������

        //    break;
        //case Keys::R:
        //    T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
        //    T = rotate(0.05f) * T; // ������� �� 0.01 ������ ������������
        //    T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
        //    break;

        //case Keys::T:
        //    T = translate(0.f, -10.f) * T; // ����� ����� �� ���� ������
        //    break;
        //case Keys::G:
        //    T = translate(0.f, 10.f) * T; // ����� ����� �� ���� ������
        //    break;
        //case Keys::F:
        //    T = translate(-10.f, 0.f) * T; // ����� ����� �� ���� ������
        //    break;
        //case Keys::H:
        //    T = translate(10.f, 0.f) * T; // ����� ����� �� ���� ������
        //    break;

        //case Keys::Z:
        //    T = (translate(-Wcx, -Wcy)) * T;
        //    T = scale(1.1) * T;
        //    T = (translate(Wcx, Wcy)) * T;
        //    break;
        //case Keys::X:
        //    T = (translate(-Wcx, -Wcy)) * T;
        //    T = scale(1 / 1.1) * T;
        //    T = (translate(Wcx, Wcy)) * T;
        //    break;

        //case Keys::J:
        //    T = (translate(-Wcx, -Wcy)) * T;
        //    T = mirrorY() * T;
        //    T = (translate(Wcx, Wcy)) * T;
        //    break;
        //case Keys::U:
        //    T = (translate(-Wcx, -Wcy)) * T;
        //    T = mirrorX() * T;
        //    T = (translate(Wcx, Wcy)) * T;
        //    break;

        //case Keys::I:
        //    T = (translate(-Wcx, -Wcy)) * T;
        //    T = scale(1.1, 1) * T;
        //    T = (translate(Wcx, Wcy)) * T;
        //    break;
        //case Keys::K:
        //    T = (translate(-Wcx, -Wcy)) * T;
        //    T = scale(1 / 1.1, 1) * T;
        //    T = (translate(Wcx, Wcy)) * T;
        //    break;


        //case Keys::O:
        //    T = (translate(-Wcx, -Wcy)) * T;
        //    T = scale(1, 1.1) * T;
        //    T = (translate(Wcx, Wcy)) * T;
        //    break;
        //case Keys::L:
        //    T = (translate(-Wcx, -Wcy)) * T;
        //    T = scale(1, 1 / 1.1) * T;
        //    T = (translate(Wcx, Wcy)) * T;
        //    break;

        //default:
        //    break;
        //}
        //Refresh();
    }

    private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
        rectCalc();
        Refresh();
    }
    private: System::Void btnOpen_Click(System::Object^ sender, System::EventArgs^ e) {
        if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            // � �������� ������� ������ ������ OK
            // ���������� ����� ����� �� openFileDialog->FileName � fileName
            wchar_t fileName[1024]; // ����������, � ������� ����������� �������� ��� �����
            for (int i = 0; i < openFileDialog->FileName->Length; i++)
                fileName[i] = openFileDialog->FileName[i];
            fileName[openFileDialog->FileName->Length] = '\0';
            // ���������� � �������� �����
            ifstream in;
            in.open(fileName);
            if (in.is_open()) {
                // ���� ������� ������
                // ���� ������� ������
                models.clear(); // ������� ��������� ������ ��������
                // ��������� ���������� ��� ������ �� �����

                mat3 M = mat3(1.f); // ������� ��� ��������� ��������� �������
                mat3 initM; // ������� ��� ���������� �������������� ������� �������
                vector<mat3> transforms; // ���� ������ ��������������
                vector<path> figure; // ������ ������� ���������� �������

                float thickness = 2; // ������� �� ��������� �� ��������� 2
                float r, g, b; // ������������ �����
                r = g = b = 0; // �������� ������������ ����� �� ��������� (������)
                string cmd; // ������ ��� ���������� ����� �������
                // ��������������� ������ � ������
                string str; // ������, � ������� ��������� ������ �����
                getline(in, str); // ��������� �� �������� ����� ������ ������
                while (in) { // ���� ��������� ������ ������� �������
                    // ������������ ������
                    if ((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#')) {
                        // ����������� ������ �� ����� � �� �����������
                        stringstream s(str); // ��������� ����� �� ������ str
                        s >> cmd;
                        if (cmd == "frame") { // ������� �����������

                            s >> Vx >> Vy; // ��������� ���������� �������� Vx � Vy 
                            aspectFig = Vx / Vy; //���������� ����������� ������

                            float aspectRect = Wx / Wy;

                            mat3 T1 = translate(-Vx / 2, -Vy / 2);
                            float S = aspectFig < aspectRect ? Wy / Vy : Wx / Vx;

                            mat3 S1 = scale(S, -S);
                            mat3 T2 = translate(Wx / 2 + Wcx, Wcy - Wy / 2);

                            initT = T2 * (S1 * T1);
                            T = initT;
                        }
                        else if (cmd == "color") { // ���� �����
                            s >> r >> g >> b; // ��������� ��� ������������ �����
                        }
                        else if (cmd == "thickness") { // ������� �����
                            s >> thickness; // ��������� �������� �������
                        }
                        else if (cmd == "path") { // ����� �����
                            vector<vec2> vertices; // ������ ����� �������
                            int N; // ���������� �����
                            s >> N;
                            string str1; // �������������� ������ ��� ������ �� �����
                            while (N > 0) { // ���� �� ��� ����� �������
                                getline(in, str1); // ��������� � str1 �� �������� ����� ��������� ������
                                // ��� ��� ���� ����������, �� �� ����� ����� ��������� �� �����
                                if ((str1.find_first_not_of(" \t\r\n") != string::npos) && (str1[0] != '#')) {
                                    // ����������� ������ �� ����� � �� �����������
                                        // ������ � ��� ���� ���������
                                    float x, y; // ���������� ��� ����������
                                    stringstream s1(str1); // ��� ���� ��������� ����� �� ������ str1
                                    s1 >> x >> y;
                                    vertices.push_back(vec2(x, y)); // ��������� ����� � ������
                                    N--; // ��������� ������� ����� ��������� ���������� �����
                                }
                            }
                            // ��� ����� �������, ���������� ������� (path) � ������ �� � ������ figure
                            figure.push_back(path(vertices, vec3(r, g, b), thickness));
                        }
                        else if (cmd == "model") { // ������ �������� ������ �������
                            float mVcx, mVcy, mVx, mVy;//��������� ������� model
                            s >> mVcx >> mVcy >> mVx >> mVy;//��������� �������� ����������
                            float S = mVx / mVy < 1 ? 2.f / mVy : 2.f / mVx;

                            // ����� ����� �������� �� ������ ��������� � ������ �������
                            // ����� �������� �������� ���������������
                            initM = scale(S) * translate(-mVcx, -mVcy);

                            figure.clear();
                        }
                        else if (cmd == "figure") { // ������������ ����� ������
                            models.push_back(model(figure, M * initM)); // ��������� ������� � ������
                        }
                        else if (cmd == "translate") { // �������
                            float Tx, Ty; // ��������� �������������� ��������
                            s >> Tx >> Ty; // ��������� ���������
                            M = translate(Tx, Ty) * M; // ��������� ������� � ������ ��������������
                        }
                        else if (cmd == "scale") { // ���������������
                            float S;
                            s >> S;
                            M = scale(S) * M;
                        }
                        else if (cmd == "rotate") { // �������
                            float theta; // ���� �������� � ��������
                            s >> theta; // ��������� ��������
                            M = rotate(-theta / 180.f * Math::PI) * M; // ��������� ������� � ������ ��������������
                        }
                        else if (cmd == "pushTransform") { // ���������� ������� � ����
                            transforms.push_back(M); //��������� ������� � ����
                        }
                        else if (cmd == "popTransform") { // ����� � ������� �� �����
                            M = transforms.back(); //�������� ������� ������� �����
							transforms.pop_back(); //���������� ������� �� �����
                        }
                    }
                    // ��������� ��������� ������
                    getline(in, str);
                }
                Refresh();
            }
        }
    }
    };
}
