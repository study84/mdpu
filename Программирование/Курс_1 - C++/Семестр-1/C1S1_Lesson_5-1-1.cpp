// ������ 4. ����� � �++����
// https://dfn.mdpu.org.ua/pluginfile.php/36266/mod_resource/content/1/�����%20�%20���%20c%2B%2B%20���%204.pdf

#include <windows.h>
#include <iostream>
#include <ctime>

using namespace std;


int main() {
	SetConsoleOutputCP(1251);

	long height[6]{};
	// long(4 bite) * 6 = 34 bite

	int a[8] = { 37, 0, 50, 46, 34, 46, 0, 13 };
	int m{};
	for (; m < 8; m++) cout << a[m] << '\t';

	// ��������� ����� �� ������ �������� ����������, �� ��������� � ��������� �� ��� ��������� ��������

	// ��������� ����� �� �'��������� �������� ���������� ����� �������� ���������� � (0 � < 10)
	// ��������� ����� �� �'��������� �������� ���������� ����� �������� ���������� � (�50 � < 50 )
	srand(time(0));
	/*unsigned int s{};
	cout << "������ ����� ������:";
	cin >> s;*/
	double mass1[15];
	int	mass2[15];
	for (int s{}; s < 15; s++) {
		mass1[s] = rand() % 15; // (0 � < 10)
		mass2[s] = static_cast<float> (rand()) / RAND_MAX * (50 - (-50)) + (-50); // (�50 � < 50 )
		cout << mass1[s] << '\t' << mass2[s] << endl;
	}

	// ������� �������� ��������� �� ����� ����-����� �������� ������ �� ���� ��������.

	const int MAX(20); // ����������� ������� ������� // ����������
	double gas[MAX]; // ����� ������� � �������
	long miles[MAX]; // ������ ��������
	int count(0); // ˳������� �����
	char indicator(' �'); // ��������� ��������

	// ������ ������: ����������� �������� ������ � ���������� ������� (�������� �������)
	const int SIZE = 10;
	int mass3[SIZE] = { 0,1,2,3,4,5,6,7,8,9 }, temp;	
	for (int i = 0; i < SIZE / 2; i++) {
		temp = mass3[i];
		mass3[i] = mass3[SIZE - i - 1];
		mass3[SIZE - i - 1] = temp;		
	}
	cout << endl;
	for (int i = 0; i < SIZE; i++)
		cout << mass3[i] << endl;

	cout << endl;
	temp = mass3[0];
	for (int i = 0; i < SIZE; i++)
		mass3[i] = (i == (SIZE - 1) ? temp : mass3[i + 1]);		
	for (int i = 0; i < SIZE; i++)
		cout << mass3[i] << endl;

	return 0;
}