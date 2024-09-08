#include <windows.h>
#include <iostream>
#include <fstream> // библиотека для работы с файлами
#include <string>
#include <format>

using namespace std;


struct Matrix {
	string source;
	unsigned short number;
	unsigned short rows;
	unsigned short columns;
	int** matrix;
	int summ = 0;

	// void create(MTRX2 &mtrx)

	// void create(const unsigned short _rows, const unsigned short _cols)
	void create() {
		//rows = _rows;
		//columns = _cols;
		matrix = new int* [rows];
		for (short r{ 0 }; r < rows; r++) {
			matrix[r] = new int[columns];
			for (short c{ 0 }; c < columns; c++) matrix[r][c] = 0;
		}
	}

	void del() {
		for (short r{ 0 }; r < rows; r++) delete[] matrix[r];
		delete[] matrix;
	}

	void print() {
		cout << format("{}: {}", number, source) << endl;
		for (short r{ 0 }; r < rows; r++) {
			for (short c{ 0 }; c < columns; c++)
				cout << matrix[r][c] << '\t';
			cout << endl;
		}
		cout << endl;
	}

	void calc() {
		summ = 0;
		for (short i{ 0 }; i < rows and i < columns; i++) {
			//cout << matrix[i][i] << '\t';
			summ += matrix[i][i];
		}
		//cout << endl;		
	}

	void test() {
		double i{ 0.1 };
		for (auto r{ 0 }; r < rows; r++) {
			i *= 10;
			for (auto c{ 0 }; c < columns; c++)
				matrix[r][c] = (c + 1) * i;
		}
	}
};




int* split(string str, char delimiter = ' ') {
	size_t start{ 0 }, stop{ 0 }, len{ str.length() }, count{ 0 };
	string s, duplication(2, delimiter), rep(1, delimiter);

	while (str.find(duplication) != string::npos) str.replace(str.find(duplication), 2, rep);
	for (auto s : str) if (s == delimiter) count++;
	//cout << format("'{}'\t{}", str, delimiter_count) << endl;

	int* arr = new int[count + 1];

	count = 0;

	while (stop < len) {
		stop = str.find(delimiter, start);
		if (stop == string::npos) stop = len;
		//s = format("'{}'", str.substr(start, stop - start));
		//cout << format("{:>5}\t{:^3}\t{:^3}", s, start, stop) << endl;
		arr[count] = stoi(str.substr(start, stop - start));
		count++;
		start = stop + 1;
	}
	return arr;
}


Matrix* get_matrix(const string file, const unsigned short rows = 5, const unsigned short columns = 5) {
	/*MTRX** arr = new MTRX*[rows];
	for (auto r{ 0 }; r < rows; r++) {
		arr[r] = new MTRX[columns];
		for (auto c{ 0 }; c < columns; c++)
			arr[r][c].number = r * 10 + c * 100;
	}
	return arr;*/

	ifstream read_file(file);
	if (read_file) {
		//cout << file << endl;
		string read_str;
		unsigned short count_str{ 0 }, count_matrix{ 0 };
		int* str_arr = new int[columns];

		while (!read_file.eof()) {
			getline(read_file, read_str);
			count_str++;
		}
		count_matrix = count_str / rows;
		cout << format("{}\t{}", count_str, count_matrix) << endl;

		read_file.seekg(0, ios::beg); // перевести коретку в начала файла

		Matrix* mtrx = new Matrix[count_matrix]; // создание массива

		for (size_t cm{ 0 }; cm < count_matrix; cm++) {
			mtrx[cm].source = file;
			mtrx[cm].number = cm;
			mtrx[cm].rows = rows;
			mtrx[cm].columns = columns;
			mtrx[cm].create();			
			for (size_t r{ 0 }; r < rows; r++) {
				getline(read_file, read_str);
				str_arr = split(read_str);
				for (size_t c{ 0 }; c < columns; c++) mtrx[cm].matrix[r][c] = str_arr[c];
			}
			mtrx[cm].calc();
			mtrx[cm].print();
		}			
		read_file.close();
		delete[] str_arr;
		return mtrx;
	}
}



int main() {
	SetConsoleOutputCP(1251);

	string folder{ "C:\\Users\\Admin\\Desktop\\files_cpp\\" };
	string files[]{ "matrix1.txt", "matrix2.txt" };

	string file = format("{}{}", folder, files[0]);	


	cout << "------------------------------------------" << endl;
	//Matrix mt;
	//mt.source = files[0];
	//mt.number = 0;
	//mt.rows = 7;
	//mt.columns = 6;

	//mt.create();
	//mt.test();
	//mt.print();
	//mt.calc();
	//cout << mt.summ << endl;
	//mt.del();
	
	
	Matrix* matrix1 = get_matrix(file, 5, 5);

	for (auto m{ 0 }; m < 3; m++) {
		cout << format("num: {}\tsumm: {}", matrix1[m].number, matrix1[m].summ) << endl;
		matrix1[m].del();
	}
	delete[] matrix1;

	return 0;
}