#include <windows.h>
#include <iostream>
#include <format>
#include <numbers>

using namespace std; //using namespace numbers;



int main() {
	SetConsoleOutputCP(1251);
	cout << "Форматування рядків за допомогою std::format()" << endl;
	
	
	// https://dfn.mdpu.org.ua/pluginfile.php/36263/mod_resource/content/3/Дані%20та%20змінні%20Лекція%201.pdf
	/*const double pi = std::numbers::pi;
	std::cout << std::format("Default: {:.2}, fixed: {:.2f}, scientific: {:.2e}, " "general: {:.2g}\n", pi, pi, pi, pi);
	std::cout << std::format("Default: {}, binary: {:b}, hex.: {:x}\n", 314, 314, 314);
	std::cout << std::format("Default: {}, decimal: {:d}, hex.: {:x}\n", 'c', 'c', 'c');
	std::cout << std::format("Alternative hex.: {:#x}, binary: {:#b}, HEX.: {:#X}\n", 314, 314, 314);
	std::cout << std::format("Forced sign: {:+}, space sign: {: }\n", 314, 314);
	std::cout << std::format("All together: {:*<+10.4f}, {:+#09x}\n", pi, 314);*/


	const double pi{ 3.14159265359 };
	//cout << std::format("{}:.2", pi);

	return 0;
}