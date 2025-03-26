#include "MainForm.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Пример3::MainForm mainForm;
	Application::Run(% mainForm);
}

System::Void Пример3::MainForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	BackColor = Color::FromArgb(255, rand() % 256, rand() % 256, rand() % 256);
	label2->Text = Convert::ToString(BackColor);
	//return System::Void();
}
