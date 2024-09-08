// Лекція 4. Цикли в С++Файл
// https://dfn.mdpu.org.ua/pluginfile.php/36266/mod_resource/content/1/Цикли%20у%20мові%20c%2B%2B%20лек%204.pdf

#include <windows.h>
#include <iostream>
#include <ctime>


using namespace std;


int main() {
	SetConsoleOutputCP(1251);

	// RANDOM
	// (rand() % 15) + 1 // интервал 1-15
	srand(time(NULL)); // генератор випадкових чисел
	int r{};
	double min{}, max{}, rd{};
	cout << "Min:";
	cin >> min;
	cout << endl;
	cout << "Max:";
	cin >> max;
	for (size_t rr{}; rr < 30; rr++) {
		r = (rand());
		rd = static_cast <double> (r) / RAND_MAX * (max - min) + min; // генерація дробових чисел у зазначеному діапазоні min...max
		cout << r << '\t' << (r % 15) + 1 << time(NULL) << '\t' << rd << endl;
	}

	return 0;
}