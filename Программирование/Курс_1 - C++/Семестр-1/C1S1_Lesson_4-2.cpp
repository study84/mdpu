// Лекція 4. Цикли в С++Файл
// https://dfn.mdpu.org.ua/pluginfile.php/36266/mod_resource/content/1/Цикли%20у%20мові%20c%2B%2B%20лек%204.pdf

#include <windows.h>
#include <iostream>
#include <typeinfo>
#include <iomanip>


using namespace std;




int main() {
	SetConsoleOutputCP(1251);

	// Використання циклу while
	double value{}, sum{};
	int i{};
	auto indikator{ 'y' };	

	while (indikator == 'y') {
		cout << "Введіть значення: ";		
		cin >> value;		
		//cout << typeid(value).name() << endl;
		++i;
		sum += value;
		break;
			
	}

	// цикл do-while


	//setw - задаёт разную ширину поля вывода строк

	cout << setw(10) << "Один" << endl;
	cout << setw(10) << "Два" << endl;
	cout << setw(10) << "Восемь" << endl;

	const int tab{ 12 };
	for (int s{ 1 }; s <= tab; s++) {
		cout << setw(4) << s;
		for (int s1{ 1 }; s1 <= tab; s1++) {
			cout << setw(4) << s * s1;
		}
		cout << endl;
	}

	return 0;
}