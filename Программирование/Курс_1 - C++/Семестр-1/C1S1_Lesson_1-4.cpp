#include <iostream>
#include <windows.h>


using namespace std;



int main() {
	SetConsoleOutputCP(1251);
	cout << "#include <windows.h> ???????????????????????" << endl;
	
	cout << "SetConsoleOutputCP(1251);" << endl;
	cout << system("IPconfig") << endl;
	cout << system("ping i.ua") << endl;
	cout << "\n" << endl;
	//cout << system("ping i.ua > d:\ping_i-ua.log") << endl;

	return 0;
}