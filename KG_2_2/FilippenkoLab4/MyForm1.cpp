#include "Matrix.h"
#include "Transform.h"
#include "Figure.h"
#include "Clip.h"
#include <vector>
#include <fstream>
#include <sstream>
#include "MyForm1.h"



using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	FilippenkoLab4::MyForm form;
	Application::Run(% form);
}