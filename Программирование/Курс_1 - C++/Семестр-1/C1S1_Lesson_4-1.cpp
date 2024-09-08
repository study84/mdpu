// ������ 4. ����� � �++����
// https://dfn.mdpu.org.ua/pluginfile.php/36266/mod_resource/content/1/�����%20�%20���%20c%2B%2B%20���%204.pdf

#include <windows.h>
#include <iostream>
#include <format>
#include <iomanip> // ???????????????????????????


using namespace std;





int main() {
	SetConsoleOutputCP(1251);
	
	
	int sum{};
	size_t i{}; // ��� size_t ������ ����������� ��� ��������� ������, ���������� ��������, �������� ��������, �������� ����������. ��� ��� ��� ������ ��������� � �������� ���������
	const auto max{ 10 };
	for (i = 1; i <= max; i++)
	{
		sum += i;
	}
	cout << endl
		<< "sum = " << sum << endl
		<< "i = " << i << endl;

	//---------------------------------------------
	for (size_t i1{}; i1 < 10; i1++) cout << i1;
	cout << '\n';

	//---------------------------------------------
	size_t i2{};
	for (; i2 < 10; i2++) cout << i2;
	cout << '\n';

	//---------------------------------------------
	size_t i3{};
	for (;;) {
		cout << i3;
		++i3;
		if (i3 >= 10) break;
	}
	cout << '\n';

	//---------------------------------------------
	const auto max1{ 10 };
	const auto table_format = "{:>10} {:>10}\n"; // ����� �������
	cout << endl;
	for (size_t i{}, power{ 1L }; (i <= max1) and (power < 256); i++, power += power) // ������������ ������ ���������
	{
		//cout << format(table_format, i, power); // �������� �����
		cout << i << '\t' << power << endl;
	}

	//---------------------------------------------	
	
	//for (char capital = 'A', small = 'a'; capital <= 'Z'; capital++, small++)
	//	cout << endl
	//	<< "\t" << capital // Output capital as a character
	//	<< hex << setw(10) << static_cast <int>(capital) // and as hexadecimal
	//	<< dec << setw(10) << static_cast <int>(capital) // and as decimal
	//	<< " " << small // Output small as a character
	//	<< hex << setw(10) << static_cast <int>(small) // and as hexadecimal
	//	<< dec << setw(10) << static_cast <int> (small); // and as decimal
	//cout << endl;
	//return 0;

	for (char capital = 'A'; capital <= 'z'; capital++) cout << capital;
	cout << endl;

	// ˳�������� � ��������� �����
	for (double d = 0.0; d <= 2.0; d += 0.25) cout << d << '\t';

	return 0;
}