// 513-i ��������� �����

//#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cmath>


using namespace std;


#define PI 3.14
#define E exp(1)


int main() {

	SetConsoleOutputCP(1251);

	printf("����������� ������ # 1\n");
	printf("Hello World!\n");
	
	printf("�������� 3. �������� '����� ����'\n");	
	int count{};
	float radius{ 0 };
	do {		
		printf_s("\t%.0d: ������ ����� ����: ", ++count);
		scanf_s("%f", &radius);
		printf_s("\t������� ����� � �������� %.2f ����� %.2f\n\n", radius, PI * pow(radius, 2));		

	} while (radius > 0);

	printf("�������� 4. � ���������� �� ���� �������� ������� �������� ���������� ������� Y\n");
	float a{ 2.56 }, b{ 7.18 }, x{ 6.37 };
	printf("\t1: %.2f\n", cos(x - a) / (pow(E, x - a) + abs(pow(b * x, 0.5))));	
	printf("\t7: %.2f\n", cos(a * x) + 5.87 / (pow(pow(b, 2) + pow(x, 3), 0.5)));
	printf("\t8: %.2f\n", (sin(x - a * b)) / (0.55 * pow(log(a * x + (b / x)), 2)));

	printf("\n");
	
	printf("�������� 5. � ���������� � ���� �������� ������� �������� ���������� ���� ������� Y1 � Y2\n");
	a = 3.56;
	b = 5.86;
	x = 2.28;
	printf("\t8: Y1=%.2f\tY2=%.2f\n", pow(E, a * x) + pow(x, 1.0 / 3), (2 * a * x - b) / (pow(b, 2) + pow(x, 4)));



	return 0;
}
