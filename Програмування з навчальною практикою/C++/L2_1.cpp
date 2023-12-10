// Лекція 2. Обчислення в С++
// https://dfn.mdpu.org.ua/pluginfile.php/36264/mod_resource/content/1/Обчислення%20у%20CPP%20Лекція%202.pdf

#include <windows.h>
#include <iostream>
#include <format>
#include <numbers>
#include <typeinfo>


using namespace std;



int main() {
	SetConsoleOutputCP(1251);

	auto a{ 17 }, b{ 5 };
	int c{}, d{}, e{}, f{}, g{}, h{}, k{}, m{};
	float x{};

	cout << "вихідні дані" << endl;
	cout << "a=" << a << '\t' << "b=" << b << endl;

	c = a + b;
	d = a - b;
	e = a * b;
	f = a / b;
	g = a % b;
	x = static_cast<float>(a) / b; // преобразования типа int > float

	cout << "результат" << endl;
	cout << "c=" << c << endl;
	cout << "d=" << d << endl;
	cout << "e=" << e << endl;
	cout << "f=" << f << endl;
	cout << "g=" << g << endl;
	cout << "x=" << x << endl;

	system("PAUSE"); // ПАуза, до нажатия на кнопку

	a++;
	b--;

	cout << "нові значення:\n" << "a=" << a << '\t' << "b=" << b << endl;

	//cput << std::format("нові значення:\na={}\tab{}", a, b);

	//const - змінна є константою
	const double rollWidth = 21.0;
	const double rollLength = 12.0 * 33.0; //33 фути


	a += 2; // добавить 2
	a -= 1; // отнять 1
	a *= 10; // умножить на 10
	a /= 5; // делить на 5
	a %= 6; // остаток от деления
	cout << a << endl;

	++a;
	cout << "++a\t->" << a << endl;

	a++;
	cout << "a++\t->" << a << endl;

	//total = ++count + 6; //Це називається префіксною формою інкременту

	a = ++a + 6;
	cout << "a = ++a + 6\t->" << a << endl;

	a = a++ + 6;
	cout << "a = a++ + 6\t->" << a << endl;

	//cout << std::numbers::pi << endl;

	//Явне приведення типів
	double v1 = 10.5;
	double v2 = 15.5;
	cout << static_cast<int>(v1) + static_cast<int>(v2) << endl;

	//З'ясування типів
	cout << typeid(v1).name() << endl;

	return 0;
}