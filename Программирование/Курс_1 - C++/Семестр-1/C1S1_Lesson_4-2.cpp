// ������ 4. ����� � �++����
// https://dfn.mdpu.org.ua/pluginfile.php/36266/mod_resource/content/1/�����%20�%20���%20c%2B%2B%20���%204.pdf

#include <windows.h>
#include <iostream>
#include <typeinfo>
#include <iomanip>


using namespace std;




int main() {
	SetConsoleOutputCP(1251);

	// ������������ ����� while
	double value{}, sum{};
	int i{};
	auto indikator{ 'y' };	

	while (indikator == 'y') {
		cout << "������ ��������: ";		
		cin >> value;		
		//cout << typeid(value).name() << endl;
		++i;
		sum += value;
		break;
			
	}

	// ���� do-while


	//setw - ����� ������ ������ ���� ������ �����

	cout << setw(10) << "����" << endl;
	cout << setw(10) << "���" << endl;
	cout << setw(10) << "������" << endl;

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