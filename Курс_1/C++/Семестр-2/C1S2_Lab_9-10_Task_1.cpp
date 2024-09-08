#include <windows.h>
#include <iostream>
#include <fstream> // библиотека для работы с файлами
#include <string>
#include <format>

using namespace std;

bool copy_past(string folder, string file);


int main() {

	cout << "8.  Дано символьні файли f1 і f2. Переписати із збереженням порядку проходження компоненти файлу f1 у файл f2.Використання допоміжного файлу h. " << endl;

	string folder{ "C:\\Users\\Admin\\Desktop\\files_cpp\\" };
	string name{"data"};
	
	copy_past(folder, name);
	
	return 0;
}


bool copy_past(string folder, string file) {	
	
	string file_read = format("{}{}.txt", folder, file);
	string file_write = format("{}{}_copy.txt", folder, file);

	bool status{false};
		
	ifstream read(file_read);

	if (read) {
		ofstream write(file_write);
		if (write) {
			string fileread;
			while (!read.eof()) {
				getline(read, fileread);
				write << fileread << endl;
				cout << fileread << endl;
			}
			write.close();
			status = true;
		}
		read.close();
	}

	return status;
}