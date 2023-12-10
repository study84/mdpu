#include <iostream>
#include <windows.h>


using std::cout;
using std::endl;



int main() {
	SetConsoleOutputCP(1251);
	cout << "Основні типи даних" << endl;
	
	signed char c1{ -7 };
	cout << "signed char c1{ -7 } = " << c1 << endl;

	unsigned char c2{ 255 };
	cout << "unsigned char c2{ 255 } = " << c2 << endl;
	
	//------------------------------------------------

	short c3{ -31000 };
	cout << "short c3{ -31000 } = " << c3 << endl;

	short int c4{ -31000 };
	cout << "short c4{ -31000 } = " << c4 << endl;

	//------------------------------------------------

	signed short c5{ -31000 };
	cout << "signed short c5{ -31000 } = " << c5 << endl;

	signed short int c6{ -31000 };
	cout << "signed short int c6{ -31000 } = " << c6 << endl;

	//------------------------------------------------

	unsigned short c7{ 65000 };
	cout << "unsigned short c7{ -31000 } = " << c7 << endl;

	unsigned short int c8{ 65000 };
	cout << "unsigned short int c8{ -31000 } = " << c8 << endl;

	cout << "long\nlong int\nsigned log\nsigned long int\nunsigned log\nunsigned long int\n" << endl;
	cout << "long long\nlong long int\nsigned long long\nsigned long long int" << endl;
	cout << "unsigned long long\nunsigned long long int" << endl;

	//------------------------------------------------

	cout << "float\ndouble\nlong doble" << endl;

	cout << "bool" << endl;

	// auto - компілятор повинен визначити тип змінної
	auto a1{ 10 }; // int
	cout << "a1=" << a1 << endl;
	auto a2{ 200UL }; // unsigned long
	cout << "a2=" << a2 << endl;
	auto a3{ 1.55f }; // float
	cout << "a3=" << a3 << endl;
	auto a4{false}; // bool
	cout << "a4=" << a4 << endl;
	//auto a5{ std::numbers::pi }; // double
	//cout << "a5=" << a5 << endl;
	auto a6 = { 10 };
	//cout << "a6=" << a6 << endl;
	auto a7 = { 1,2,3 };
	//cout << "a7=" << a7 << endl;

	// auto test() {}

	return 0;
}