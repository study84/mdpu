// ������ 3. ��������� �����
// https://dfn.mdpu.org.ua/pluginfile.php/36265/mod_resource/content/1/c%2B%2B���������%20�����%20���3.pdf

#include <windows.h>
#include <iostream>
#include <compare> // Required when using operator <=> (even for fundamental types)

using namespace std;

/*
�������� ����
����, �� �������� ���� ���� ������� � ������� (��� ����� ������� �����), ����������� �����������, ���� ����� ��������� �������
�������� (��� ����� ���������� ������� �������� ����������� �������� ���� ��� ������� �������� ����� ).
�������� ���� ����� �� ���������� ����� �������� ��������� ���������
*/
long count1{ 999L };



int main() {
	SetConsoleOutputCP(1251);
		
	/*
	������� ��� ��������� ��������� ������ :
		� �����������;
		� ��������;
		� ��������
	*/

	cout << "count1 (�������� �� ����������� ���) = " << count1 << endl;

	{
		cout << "{" << endl;
		int count1{ 10 };
		cout << "\tcount1 (�������� � ��������� �����) = " << count1 << endl;

		cout << "\tcount1 (�������� �� ����������� ���) = " << ::count1 << endl;

		count1 += ::count1;
		cout << "\tcount1 + ::count1 (�������� � ��������� �����) = " << count1 << endl;

		++::count1;
		cout << "\t++count1 (�������� �� ����������� ���) = " << ::count1 << endl;

		cout << "}" << endl;
		
	}

	/*
	������� ����
	��������� ���� ��������� ��������� ����� , �� �� ������� �������� � ����� �����, ��� ����������� ��������� ����� ���������. ������������ static ��������� ���� ���������.
	static int count;
	*/

	/*char letter{ 0 };
	cin >> letter;
	if ((letter >= ' �') && (letter <= 'Z')) cout << " �� ������ �����.";*/
	
	
	int a{10}, b{5};
	cout << "��������� IF" << (a > b ? "+" : 0) << endl;

	//std::strong_ordering ordering{ 10 <=> 0 }; ???????????????????????????????????????????????

	char letter{};
	std::cout << "������ �����: ";
	std::cin >> letter;
	if (std::isalpha(letter))
	{
		switch (std::tolower(letter))
		{
		case 'a': case 'e': case 'i': case 'o': case 'u':
			cout << "�� ����� ������� �����." << endl; break;
		default: cout << "�� ����� ����������." << endl; break;
		}
	}
	else cout << "�� �� ����� �����." << endl;

	return 0;
}