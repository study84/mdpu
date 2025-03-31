#include "pch.h"
#include "Form1.h"
// #include "Form1.h"


System::Void Пример_4_2::Form1::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	isChange = true;
	//return System::Void();
}


System::Void Пример_4_2::Form1::newToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (OpportunityToSave(sender, e) == false) return;
	path = nullptr;
	textBox1->Clear();

	
	//return System::Void();
}




System::Void Пример_4_2::Form1::openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	//if (OpportunityToSave(sender, e) == false) return;

	if (path) openFileDialog1->FileName = path;
	if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
		if (openFileDialog1->FileName->Length > 0) {
			path = openFileDialog1->FileName;
			textBox1->Text = IO::File::ReadAllText(path);
			isChange = false;
		}
	}
    
    //return System::Void();
}

System::Void Пример_4_2::Form1::saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (path == nullptr) {
		saveAsToolStripMenuItem_Click(sender, e);
		return;
	}
	IO::File::WriteAllText(path, textBox1->Text);
	isChange = false;
	
	//return System::Void();
}

System::Void Пример_4_2::Form1::saveAsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (path) saveFileDialog1->FileName = path;
	if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
		if (saveFileDialog1->FileName->Length > 0) {
			path = saveFileDialog1->FileName;
			IO::File::WriteAllText(path, textBox1->Text);
			isChange = false;
		}
	}
	
	//return System::Void();
}

System::Void Пример_4_2::Form1::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (OpportunityToSave(sender, e) == false) return;
	Close();
	//return System::Void();
}


//Створює діалогове вікно, з пропозицією зберегти файл (якщо в ньому були зміни)
bool Пример_4_2::Form1::OpportunityToSave(System::Object^ sender, System::EventArgs^ e)
{
	if (isChange) {
		String^ message = "The file has been modified. Do you want to save your changes?";
		String^ caption = "Notepad";
		switch (MessageBox::Show(message, caption, MessageBoxButtons::YesNoCancel))
		{
		case Windows::Forms::DialogResult::Yes:
			saveToolStripMenuItem_Click(sender, e);
			if (isChange) return false;
			break;
		case Windows::Forms::DialogResult::No:
			return true;
		case Windows::Forms::DialogResult::Cancel:
			return false;
		}
	}
	return true;
}


System::Void Пример_4_2::Form1::fontToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	FontSetting1^ myform = gcnew FontSetting1();
	myform->ShowDialog();
	//return System::Void();
}

System::Void Пример_4_2::Form1::aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm^ myform = gcnew MyForm();
	myform->ShowDialog();
	//return System::Void();
}