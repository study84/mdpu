#include "pch.h"
#include "FontSetting1.h"

System::Void Пример_4_2::FontSetting1::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Font = this->textBox1->Font;
	
	//return System::Void();
}
