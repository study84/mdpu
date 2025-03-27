#include "Conv.h"
#include <string>

using namespace System;
using namespace System::Windows::Forms;
//using namespace std;

[STAThreadAttribute]

void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Завдання3::Conv mainForm;
	Application::Run(% mainForm);
}

unsigned short List1, List2, List3, index;


System::Void Завдання3::Conv::listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	//label2->Text = Convert::ToString(listBox1->SelectedIndex);
	
	List1 = (listBox1->SelectedIndex + 1) * 100;
	listBox2->Items->Clear();
	listBox3->Items->Clear();

	switch (List1)
	{
		case 100: {
			//for (const std::string item : { "Фунт", "Кілограм", "Унція"}) {
			//	listBox2->Items->Add("1");
			//	listBox3->Items->Add("2");
			//	//test->Text = item;
			//}
			array<String^>^ items1 = { "Фунт", "Кілограм", "Унція" };
			for (int i = 0; i < items1->Length; ++i) {
				listBox2->Items->Add(items1[i]);
				listBox3->Items->Add(items1[i]);
			}
			break;
		}

		case 200: {
			array<String^>^ items2 = { "Дюйм", "Кілометр", "Метр" };
			for (int i = 0; i < items2->Length; ++i) {
				listBox2->Items->Add(items2[i]);
				listBox3->Items->Add(items2[i]);
			}
			break;
		}

		case 300: {
			array<String^>^ items3 = { "Барель", "Галон", "Літр" };
			for (int i = 0; i < items3->Length; ++i) {
				listBox2->Items->Add(items3[i]);
				listBox3->Items->Add(items3[i]);
			}
			break;
		}

		case 400: {
			array<String^>^ items4 = { "Гектар", "Квадратний метр", "Сотка " };
			for (int i = 0; i < items4->Length; ++i) {
				listBox2->Items->Add(items4[i]);
				listBox3->Items->Add(items4[i]);
			}
			break;
		}

	}	
	listBox2->SelectedIndex = 0;
	listBox3->SelectedIndex = 0;
	//return System::Void();
}

System::Void Завдання3::Conv::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	List2 = (listBox2->SelectedIndex + 1) * 10;
	List3 = listBox3->SelectedIndex + 1;
	index = List1 + List2 + List3;
	//test->Text = Convert::ToString(index);
	try {
		double value = Convert::ToDouble(textBox1->Text);
		switch (index)
		{
			case 111: textBox2->Text = textBox1->Text; break;
			case 112: textBox2->Text = (value * 0.453592).ToString(); break;
			case 113: textBox2->Text = (value * 16).ToString(); break;
			///
			case 121: textBox2->Text = (value * 2.20462).ToString(); break;
			case 122: textBox2->Text = textBox1->Text; break;
			case 123: textBox2->Text = (value * 35.274).ToString(); break;
			//
			case 131: textBox2->Text = (value / 16).ToString(); break;
			case 132: textBox2->Text = (value * 0.0283495).ToString(); break;
			case 133: textBox2->Text = textBox1->Text; break;
			///
			case 211: textBox2->Text = textBox1->Text; break;
			case 212: textBox2->Text = (value * 0.0000254).ToString(); break;
			case 213: textBox2->Text = (value * 0.0254).ToString(); break;
			///
			case 221: textBox2->Text = (value * 39370.1).ToString(); break;
			case 222: textBox2->Text = textBox1->Text; break;
			case 223: textBox2->Text = (value * 1000).ToString(); break;
			///
			case 311: textBox2->Text = textBox1->Text; break;
			case 312: textBox2->Text = (value * 42).ToString(); break;
			case 313: textBox2->Text = (value * 158.987).ToString(); break;
			///
			case 411: textBox2->Text = textBox1->Text; break;
			case 412: textBox2->Text = (value * 10000).ToString(); break;
			case 413: textBox2->Text = (value * 100).ToString(); break;


			default: textBox2->Text = "метод конвертації не визначено"; break; //МЕТОД КОНВЕРТАЦІЇ НЕ ВИЗНАЧЕНО
		}	
	}
	catch (FormatException^ e) {
		textBox2->Text = "помилка перетворення значення";
	}	
	//return System::Void();
}

