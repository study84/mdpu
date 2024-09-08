#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <format>
#include <regex>


using namespace std;


#define DELIMITER '|'
#define DUPLICATION (string(2, DELIMITER));

#define FILE "d:\\_workers.txt"
unsigned short ROWS{ 0 }; // Кількість рядків у файлі


struct worker {
	struct row {
		unsigned short num; // номер рядка
		unsigned short start; //
		unsigned short len; //
		bool filter; // true - відповідає фільтрам, false - НЕ відповідає фільтрам
		bool del; // позначка на видалення
	} row;

	struct birthday {
		unsigned short date;
		string date_str;
	} birthday; // дата народження TS

	string surname; // Прізвище 
	string name; // ім'я	
	string nationality; // національність
	string education; // освіта

	unsigned short id; //  табельний номер
	struct employed {
		unsigned short date;
		string date_str;
	} employed; // рік прийняття на роботу
};


struct filter {
	enum status_ { ALL, ONLY, NOT_ONLY };
#define _ALL filter::status_::ALL
#define _ONLY filter::status_::ONLY
#define _NOT_ONLY filter::status_::NOT_ONLY
	struct birthday {
		unsigned short dateFrom;
		unsigned short dateTo;
	} birthday;
	struct { status_ status; string values; } surnames;
	struct { status_ status; string values; } names;
	struct { status_ status; string values; } nationalities;
	struct { status_ status; string values; } education;
	struct { status_ status; string values; } ids;
	struct employed {
		unsigned short dateFrom;
		unsigned short dateTo;
	} employed;
	unsigned short rows;
	unsigned short begin;
	bool apply_filter;
};

filter FILTER;

filter::status_ statusValues[]{ _ALL, _ONLY, _NOT_ONLY };
const string types[3]{ "ALL", "ONLY", "NOT ONLY" };


struct Sort {
	bool status = false;
	//bool* arr_status = new bool[]{ false, false, false, false, false, false, false };
	const short attributes = 7;
	bool* status_list = new bool[attributes];
	unsigned short cell = 0;
	enum type { NO_SORT, ASC, DESC }; // asc=01, desc=10
	const string desc[3]{ "NO_SORT", "ASC", "DESC" };
	struct { short cascade; type type; } birthday;
	struct { short cascade; type type; } surname;
	struct { short cascade; type type; } name;
	struct { short cascade; type type; } nationality;
	struct { short cascade; type type; } education;
	struct { short cascade; type type; } id;
	struct { short cascade; type type; } employed;
};

Sort SORT;


struct Pattern {
	string str;
	unsigned short start;
	unsigned short count;
};


bool isLeapYear(const unsigned short year);
bool validator(const string str, char type_test = 'd');
short date_convert(const string& date);
string date_convert(unsigned short days);
string* split(string str);
void filter_setting(worker* workers);
bool filter_setting_str(const string text, filter::status_& type, string& values);
bool filter_apply_valid(const filter::status_& filter_status, const string& filter_values, const string& worker_value);
void filter_apply(worker* workers);
void filter_reset(worker* workers);
void sort_setting(worker* workers);
void sort(worker* workers, const unsigned short cascade, const unsigned short start, const unsigned short end);
void sort_reset();
void print(const worker* workers);

worker* File_Read(const string file, unsigned short& ROWS);
worker* File_Write(const string file, unsigned short& ROWS);

worker* create(worker* old_data, unsigned short& rows);
worker* edit(worker* workers, unsigned short& rows);
worker* del(worker* workers, unsigned short& rows);


auto concate_attributes = [](worker& worker, const unsigned cascade) {
	string pattern;
	for (unsigned short c{ 0 }; c < cascade + 1; c++) {
		if (SORT.birthday.cascade == c) pattern += format("{}{}", worker.birthday.date, DELIMITER);
		else if (SORT.surname.cascade == c) pattern += format("{}{}", worker.surname, DELIMITER);
		else if (SORT.name.cascade == c) pattern += format("{}{}", worker.name, DELIMITER);
		else if (SORT.nationality.cascade == c) pattern += format("{}{}", worker.nationality, DELIMITER);
		else if (SORT.education.cascade == c) pattern += format("{}{}", worker.education, DELIMITER);
		else if (SORT.id.cascade == c) pattern += format("{}{}", worker.id, DELIMITER);
		else if (SORT.employed.cascade == c) pattern += format("{}{}", worker.employed.date, DELIMITER);
	}
	//cout << "concate_attributes(lambda): " << pattern << endl;
	return pattern;
	};


string* gen_data(const unsigned short count);
void test();

//////////////////////////////////////////////////////////////////////////////



int main() {

	SetConsoleOutputCP(1251);


	//test();

	//gen_data(100);


	worker* workers = File_Read(FILE, ROWS);
	//cout << "Rows: " << ROWS << '\t' << sizeof(workers) / sizeof(workers[0]) << endl;

	filter_reset(workers);
	sort_reset();

	bool status{ true };
	char select;

	do {
		print(workers);
		cin >> select;
		cout << endl;
		switch (select)
		{
		case '1': break;
		case '2': filter_setting(workers); break;
		case '3': sort_setting(workers); break;
		case '4': workers = create(workers, ROWS); break;
		case '5': workers = edit(workers, ROWS); break;
		case '6': workers = del(workers, ROWS); break;
		default: status = false; break;
		}
		cout << endl;
	} while (status);

	delete[] workers;


	////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////

	//string file_name{ "D:\\_C++ TEST\\_example.txt" };
	//reset_file(file_name);
	////string newText{ "9033|AAAA|ZZZ|A|A|007|15943\n" }; // Новий текст для вставки
	//string text{ "TEST_WRIGHT\n" }; // Новий текст для вставки
	//cout << sizeof(text) << endl;

	//unsigned short position; // Позиція для редагування
	//cout << "Введіть позицію для редагування: ";
	//cin >> position;
	//cin.ignore(); // Очищуємо вхідний потік
	////--------------------------------

	//editFile(file_name, position, text);
	//
	////////////=============================
	//
	//streampos positionToInsert = position; // Example position
	////insertText(file_name, text, positionToInsert);

	return 0;
}


bool isLeapYear(const unsigned short year) {
	// рік високосний: y-true / n-false
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}


bool validator(const string str, char type_test) {
	bool status{ false };
	switch (type_test)
	{
		// валідатор формату дати
	case 'D': case 'd':
	{
		// \b(19[6-9][0-9]|20[0-9][0-9])-(0[1-9]|1[0-2])-(0[1-9]|1[0-9]|2[0-9]|3[0-1])\b
		// \b(19[6-9][0-9]|20[0-9][0-9])-(0[1-9]|1[0-2])-([0-2][1-9]|3[0-1])\b
		static const regex pattern_date("\\b(19[6-9][0-9]|20[0-9][0-9])-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])\\b");
		status = regex_match(str, pattern_date);
		break;
	}
	// валідатор формату чисел
	case 'N': case 'n':
	{
		static const regex pattern_number("\\b\\d+\\b");
		status = regex_match(str, pattern_number);
		break;
	}
	}
	return status;
}


short date_convert(const string& date) {
	// перетворення дати рядок у дату кількість днів із 1960-01-01
	int  days{ -1 };
	if (validator(date)) {
		days = 0;
		unsigned short year;
		unsigned short month;
		unsigned short day;

		year = stoi(date.substr(0, 4));
		month = stoi(date.substr(5, 2));
		day = stoi(date.substr(8, 2));

		for (short y{ 1960 }; y < year; y++)
			days += (isLeapYear(y) ? 366 : 365);

		for (short m{ 1 }; m < month; m++) {
			switch (m)
			{
			case 2: days += (isLeapYear(year) ? 29 : 28); break;
			case 4: case 6: case 9: case 11: days += 30; break;
			default: days += 31; break;
			}
		}
		days += day;
	}
	return days;
}


string date_convert(unsigned short days) {
	// перетворення дати з кількість днів з 1960-01-01 у дату рядок
	string date{ "NO DATA" };
	unsigned short d[]{ 1960, 1, 1 };

	while (days >= (366 - !isLeapYear(d[0]))) {
		days -= (366 - !isLeapYear(d[0]));
		d[0] += 1;
	}

	int months_days[]{ 31, (29 - !isLeapYear(d[0])), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	short month{ 0 };
	while (days >= months_days[month]) {
		days -= months_days[month];
		d[1]++;
		month++;
	}

	d[2] += days;

	date = format("{}-{:0>2}-{:0>2}", d[0], d[1], d[2]);
	return validator(date) ? date : format("{} - невірний формат дати!", date);
}


string* split(string str) {
	size_t start{ 0 }, stop{ 0 }, len{ str.length() }, count{ 0 };
	string duplication(2, DELIMITER), rep(1, DELIMITER);

	while (str.find(duplication) != string::npos) str.replace(str.find(duplication), 2, rep);
	for (auto s : str) if (s == DELIMITER) count++;
	//cout << format("'{}'\t{}", str, delimiter_count) << endl;	

	string* row = new string[count + 1];

	count = 0;

	while (stop < len) {
		stop = str.find(DELIMITER, start);
		if (stop == string::npos) stop = len;
		//s = format("'{}'", str.substr(start, stop - start));
		//cout << format("{:>5}\t{:^3}\t{:^3}", s, start, stop) << endl;		
		row[count] = str.substr(start, stop - start);
		count++;
		start = stop + 1;
	}
	return row;
}


void filter_setting(worker* workers) {
	cout << endl;
	bool status{ true };
	string titles[]{ "Дата народження", "Прізвище", "Ім'я", "Національність", "Освіта", "Табельний номер", "Працевлаштований", "Кількість рядків" };
	FILTER.apply_filter = true;
	FILTER.begin = 0;
	string value;
	do {
		cout << "\tПоточні налаштування фільтрів:" << endl;
		cout << format("\t1 {:<16}\t{} - {}", titles[0], date_convert(FILTER.birthday.dateFrom), date_convert(FILTER.birthday.dateTo)) << endl;
		cout << format("\t2 {:<16}\t{}\t'{}'", titles[1], types[FILTER.surnames.status], FILTER.surnames.status ? FILTER.surnames.values : "") << endl;
		cout << format("\t3 {:<16}\t{}\t'{}'", titles[2], types[FILTER.names.status], FILTER.names.status ? FILTER.names.values : "") << endl;
		cout << format("\t4 {:<16}\t{}\t'{}'", titles[3], types[FILTER.nationalities.status], FILTER.nationalities.status ? FILTER.nationalities.values : "") << endl;
		cout << format("\t5 {:<16}\t{}\t'{}'", titles[4], types[FILTER.education.status], FILTER.education.status ? FILTER.education.values : "") << endl;
		cout << format("\t6 {:<16}\t{}\t'{}'", titles[5], types[FILTER.ids.status], FILTER.ids.status ? FILTER.ids.values : "") << endl;
		cout << format("\t7 {:<16}\t{} - {}", titles[6], date_convert(FILTER.employed.dateFrom), date_convert(FILTER.employed.dateTo)) << endl;
		cout << format("\t8 {:<16}\t{}", titles[7], FILTER.rows) << endl;
		cout << "\tВведіть RESET - скинути всі налаштування" << endl;
		cout << "\tВиберіть у якій колонці хочете налаштувати фільтрацію: ";
		cin >> value;
		cin.ignore();
		if (value == "1") {
			do {
				cout << "\t1 Дата народження початкову дату >= 'YYYYY-mm-dd'? ";
				cin >> value;
				cout << endl;
			} while (!validator(value));
			FILTER.birthday.dateFrom = date_convert(value);
			do {
				cout << "\t1 Дата народження кінцеву дату <= 'YYYYY-mm-dd'? ";
				cin >> value;
				cout << endl;
			} while (!validator(value));
			FILTER.birthday.dateTo = date_convert(value);
		}
		else if (value == "2") filter_setting_str("\t2 прізвища", FILTER.surnames.status, FILTER.surnames.values);
		else if (value == "3") filter_setting_str("\t3 імена", FILTER.names.status, FILTER.names.values);
		else if (value == "4") filter_setting_str("\t4 національності", FILTER.nationalities.status, FILTER.nationalities.values);
		else if (value == "5") filter_setting_str("\t5 освіту", FILTER.education.status, FILTER.education.values);
		else if (value == "6") filter_setting_str("\t6 табельні номери", FILTER.ids.status, FILTER.ids.values);
		else if (value == "7") {
			do {
				cout << "\t7 Працевлаштований початкову дату >= 'YYYYY-mm-dd'? ";
				cin >> value;
				cout << endl;
			} while (!validator(value));
			FILTER.employed.dateFrom = date_convert(value);
			do {
				cout << "\t7 Працевлаштований початкову дату <= 'YYYYY-mm-dd'? ";
				cin >> value;
				cout << endl;
			} while (!validator(value));
			FILTER.employed.dateTo = date_convert(value);
		}
		else if (value == "8") {
			do {
				cout << "\t8 Кількість рядків вивдити? ";
				cin >> value;
			} while (!validator(value, 'n'));
			FILTER.rows = stoi(value);
		}
		else if (value == "RESET") {
			filter_reset(workers);
		}
		else status = false;
		cout << endl;
	} while (status);


	if (FILTER.apply_filter) filter_apply(workers);
	cout << endl;
}


bool filter_setting_str(const string text, filter::status_& type, string& values) {

	unsigned short input_new_status;
	filter::status_ new_status;
	filter::status_ statusValues[]{ _ALL, _ONLY, _NOT_ONLY };
	do {
		cout << format("{} == {} << [ 1=ALL  2=ONLY  3=NOT ONLY ] ", text, types[type]);
		cin >> input_new_status;
		cin.ignore();
		input_new_status--;
		new_status = static_cast<filter::status_>(input_new_status);
	} while (!(new_status == filter::ALL || new_status == filter::ONLY || new_status == filter::NOT_ONLY));

	type = statusValues[input_new_status];

	switch (new_status)
	{
	case 1: case 2:
		//cout << endl;
		cout << format("{} == {} Values (DELIMITER='{}'): ", text, types[type], DELIMITER);
		cin >> values;
		cin.ignore();
		//getline(cin, values);
		cout << endl;
		break;
	default: values = ""; break;
	}
	//FILTER.apply_filter = true;
	return true;
}


bool filter_apply_valid(const filter::status_& filter_status, const string& filter_values, const string& worker_value) {
	bool status{ false };
	switch (filter_status)
	{
	case 0: status = true; break; // ALL
	case 1: if (filter_values.find(worker_value) != string::npos) status = true; break; // ONLY
	case 2: if (filter_values.find(worker_value) == string::npos) status = true; break; // NOT ONLY
	}
	return status;
}


void filter_apply(worker* workers) {
	for (auto i{ 0 }; i < ROWS; i++) {
		workers[i].row.filter = false;
		if (FILTER.birthday.dateFrom <= workers[i].birthday.date and workers[i].birthday.date <= FILTER.birthday.dateTo)
			if (FILTER.employed.dateFrom <= workers[i].employed.date and workers[i].employed.date <= FILTER.employed.dateTo)
				if (filter_apply_valid(FILTER.surnames.status, FILTER.surnames.values, workers[i].surname))
					if (filter_apply_valid(FILTER.names.status, FILTER.names.values, workers[i].name))
						if (filter_apply_valid(FILTER.nationalities.status, FILTER.nationalities.values, workers[i].nationality))
							if (filter_apply_valid(FILTER.education.status, FILTER.education.values, workers[i].education))
								if (filter_apply_valid(FILTER.ids.status, FILTER.ids.values, to_string(workers[i].id)))
									workers[i].row.filter = true;
	}
}


void filter_reset(worker* workers) {
	FILTER.birthday.dateFrom = 0;
	FILTER.birthday.dateTo = 31412;
	FILTER.surnames.status = _ALL;
	FILTER.surnames.values = "";
	FILTER.names.status = _ALL;
	FILTER.names.values = "";
	FILTER.nationalities.status = _ALL;
	FILTER.nationalities.values = "";
	FILTER.education.status = _ALL;
	FILTER.education.values = "";
	FILTER.ids.status = _ALL;
	FILTER.ids.values = "";
	FILTER.employed.dateFrom = 0;
	FILTER.employed.dateTo = 31412;
	FILTER.rows = 10;
	FILTER.begin = 0;
	FILTER.apply_filter = false;
	for (auto i{ 0 }; i < ROWS; i++) workers[i].row.filter = true;
}


worker* File_Read(const string file, unsigned short& ROWS) {
	ifstream read_file(file);

	if (read_file) {
		string read_str, duplication(2, DELIMITER), rep(1, DELIMITER);
		unsigned short count_str{ 0 }, count{ 0 };

		while (!read_file.eof()) {
			getline(read_file, read_str);
			count_str++;
		}
		//cout << "Rows: " << count_str << endl;

		ROWS = count_str;
		worker* workers = new worker[count_str];
		count_str = 0;

		while (read_str.find(duplication) != string::npos) read_str.replace(read_str.find(duplication), 2, rep);
		for (auto s : read_str) if (s == DELIMITER) count++;
		string* row = new string[count];

		read_file.seekg(0, ios::beg); // перевести коретку в начала файла

		unsigned short total_len{ 0 };

		while (!read_file.eof()) {
			getline(read_file, read_str);
			//cout << read_str << endl;
			row = split(read_str);
			workers[count_str].row.num = count_str;
			workers[count_str].row.start = total_len;
			workers[count_str].row.len = read_str.length();
			//total_len += workers[count_str].row.len;
			total_len += sizeof(read_str);
			workers[count_str].row.filter = true;
			workers[count_str].row.del = false;
			workers[count_str].birthday.date = stoi(row[0]);
			workers[count_str].birthday.date_str = date_convert(workers[count_str].birthday.date);
			workers[count_str].surname = row[1];
			workers[count_str].name = row[2];
			workers[count_str].nationality = row[3];
			workers[count_str].education = row[4];
			workers[count_str].id = stoi(row[5]);
			workers[count_str].employed.date = stoi(row[6]);
			workers[count_str].employed.date_str = date_convert(workers[count_str].employed.date);
			count_str++;
		}

		read_file.close();
		return workers;
	}
}


void sort_setting(worker* workers) {
	string title, line, sorts;
	bool status = true;

	auto desc = [](const unsigned short item) {
		string info;
		if (item == 1 and SORT.birthday.cascade > -1) info = format("{}={}", SORT.birthday.cascade, SORT.desc[SORT.birthday.type]);
		else if (item == 2 and SORT.surname.cascade > -1) info = format("{}={}", SORT.surname.cascade, SORT.desc[SORT.surname.type]);
		else if (item == 3 and SORT.name.cascade > -1) info = format("{}={}", SORT.name.cascade, SORT.desc[SORT.name.type]);
		else if (item == 4 and SORT.nationality.cascade > -1) info = format("{}={}", SORT.nationality.cascade, SORT.desc[SORT.nationality.type]);
		else if (item == 5 and SORT.education.cascade > -1) info = format("{}={}", SORT.education.cascade, SORT.desc[SORT.education.type]);
		else if (item == 6 and SORT.id.cascade > -1) info = format("{}={}", SORT.id.cascade, SORT.desc[SORT.id.type]);
		else if (item == 7 and SORT.employed.cascade > -1) info = format("{}={}", SORT.employed.cascade, SORT.desc[SORT.employed.type]);
		return info;
		};

	auto upp = [](string settings) {
		string upp_settings;
		for (auto s : settings) upp_settings += toupper(s);
		return upp_settings;
		};

	do {
		cout << "\n\n" << "\tSort settings:" << endl;
		title = format("\t{:<10}\t{:<10}\t{:<10}\t{:<10}\t{:<8}\t{:<8}\t{:<10}", "1-Birthday", "2-Surname", "3-Name", "4-Nation", "5-Edu", "6-ID", "7-Employed");
		sorts = format("\t{:<10}\t{:<10}\t{:<10}\t{:<10}\t{:<8}\t{:<8}\t{:<10}", desc(1), desc(2), desc(3), desc(4), desc(5), desc(6), desc(7));

		line = string(title.length() * 1.5, '-');
		cout << title << endl;
		cout << sorts << endl;
		cout << '\t' << line << endl;

		string settings;
		//cout << "\tОберіть колонку для налаштування правила(RESET - скидання налаштувань): ";		
		cout << "\tRESET - скидання налаштувань\tEXIT - Вихід\n\tВведіть правило сортування(| роздільник): ";
		cin >> settings;

		if (upp(settings) == "EXIT") { cout << "\n\n" << endl; status = false; }
		else if (upp(settings) == "RESET") sort_reset();
		else if (settings.length()) {
			sort_reset();
			SORT.status = true;
			unsigned short size{ 1 };
			for (auto i{ 0 }; i < settings.length(); i++) {
				settings[i] = toupper(settings[i]);
				if (settings[i] == DELIMITER) size++;
			}
			string* rules = split(settings);
			//for(auto i{ 0 }; i < size; i++) cout << '\t' << rules[i];
			//cout << rules[0][0] << '\t' << (rules[0][0] == '1') << endl;
			for (auto i{ 0 }; i < size; i++) {
				SORT.status_list[i] = true;
				if (rules[i][0] == '1' and rules[i].find("ASC") != string::npos) { SORT.birthday.cascade = i; SORT.birthday.type = Sort::type::ASC; }
				else if (rules[i][0] == '1' and rules[i].find("DESC") != string::npos) { SORT.birthday.cascade = i; SORT.birthday.type = Sort::type::DESC; }
				else if (rules[i][0] == '2' and rules[i].find("ASC") != string::npos) { SORT.surname.cascade = i; SORT.surname.type = Sort::type::ASC; }
				else if (rules[i][0] == '2' and rules[i].find("DESC") != string::npos) { SORT.surname.cascade = i; SORT.surname.type = Sort::type::DESC; }
				else if (rules[i][0] == '3' and rules[i].find("ASC") != string::npos) { SORT.name.cascade = i; SORT.name.type = Sort::type::ASC; }
				else if (rules[i][0] == '3' and rules[i].find("DESC") != string::npos) { SORT.name.cascade = i; SORT.name.type = Sort::type::DESC; }
				else if (rules[i][0] == '4' and rules[i].find("ASC") != string::npos) { SORT.nationality.cascade = i; SORT.nationality.type = Sort::type::ASC; }
				else if (rules[i][0] == '4' and rules[i].find("DESC") != string::npos) { SORT.nationality.cascade = i; SORT.nationality.type = Sort::type::DESC; }
				else if (rules[i][0] == '5' and rules[i].find("ASC") != string::npos) { SORT.education.cascade = i; SORT.education.type = Sort::type::ASC; }
				else if (rules[i][0] == '5' and rules[i].find("DESC") != string::npos) { SORT.education.cascade = i; SORT.education.type = Sort::type::DESC; }
				else if (rules[i][0] == '6' and rules[i].find("ASC") != string::npos) { SORT.id.cascade = i; SORT.id.type = Sort::type::ASC; }
				else if (rules[i][0] == '6' and rules[i].find("DESC") != string::npos) { SORT.id.cascade = i; SORT.id.type = Sort::type::DESC; }
				else if (rules[i][0] == '7' and rules[i].find("ASC") != string::npos) { SORT.employed.cascade = i; SORT.employed.type = Sort::type::ASC; }
				else if (rules[i][0] == '7' and rules[i].find("DESC") != string::npos) { SORT.employed.cascade = i; SORT.employed.type = Sort::type::DESC; }
			}
			sort(workers, 0, 0, ROWS);
		}

	} while (status);
}


void sort(worker* workers, const unsigned short cascade, const unsigned short start, const unsigned short end) {
	if (SORT.status) {
		for (auto i{ start }; i < end; i++) {
			for (auto n{ i + 1 }; n < end; n++)
				if (cascade == SORT.birthday.cascade && SORT.birthday.type == Sort::type::ASC && workers[i].birthday.date > workers[n].birthday.date) swap(workers[i], workers[n]);
				else if (cascade == SORT.birthday.cascade && SORT.birthday.type == Sort::type::DESC && workers[i].birthday.date < workers[n].birthday.date) swap(workers[i], workers[n]);
				else if (cascade == SORT.surname.cascade && SORT.surname.type == Sort::type::ASC && workers[i].surname > workers[n].surname) swap(workers[i], workers[n]);
				else if (cascade == SORT.surname.cascade && SORT.surname.type == Sort::type::DESC && workers[i].surname < workers[n].surname) swap(workers[i], workers[n]);
				else if (cascade == SORT.name.cascade && SORT.name.type == Sort::type::ASC && workers[i].name > workers[n].name) swap(workers[i], workers[n]);
				else if (cascade == SORT.name.cascade && SORT.name.type == Sort::type::DESC && workers[i].name < workers[n].name) swap(workers[i], workers[n]);
				else if (cascade == SORT.nationality.cascade && SORT.nationality.type == Sort::type::ASC && workers[i].nationality > workers[n].nationality) swap(workers[i], workers[n]);
				else if (cascade == SORT.nationality.cascade && SORT.nationality.type == Sort::type::DESC && workers[i].nationality < workers[n].nationality) swap(workers[i], workers[n]);
				else if (cascade == SORT.education.cascade && SORT.education.type == Sort::type::ASC && workers[i].education > workers[n].education) swap(workers[i], workers[n]);
				else if (cascade == SORT.education.cascade && SORT.education.type == Sort::type::DESC && workers[i].education < workers[n].education) swap(workers[i], workers[n]);
				else if (cascade == SORT.id.cascade && SORT.id.type == Sort::type::ASC && workers[i].id > workers[n].id) swap(workers[i], workers[n]);
				else if (cascade == SORT.id.cascade && SORT.id.type == Sort::type::DESC && workers[i].id < workers[n].id) swap(workers[i], workers[n]);
				else if (cascade == SORT.employed.cascade && SORT.employed.type == Sort::type::ASC && workers[i].employed.date > workers[n].employed.date) swap(workers[i], workers[n]);
				else if (cascade == SORT.employed.cascade && SORT.employed.type == Sort::type::DESC && workers[i].employed.date < workers[n].employed.date) swap(workers[i], workers[n]);
		}

		//(cascade + 1) < SORT.attributes ? SORT.status_list[(cascade + 1)] : false
		//if ((cascade + 1) < SORT.attributes and SORT.status_list[(cascade + 1)]) {
		//	//cout << cascade << '\t' << SORT.status_list[(cascade + 1)] << endl;
		//	Pattern pattern = { "", 0, 0 };
		//	for (unsigned short i{ start }; i < end; i++) {
		//		if (pattern.str == "") {
		//			pattern.str = concate_attributes(workers[i], cascade);
		//			//cout << pattern.str << endl;
		//			pattern.start = i;
		//		}
		//		else {
		//			if (pattern.str == concate_attributes(workers[i], cascade)) pattern.count++;
		//			else {
		//				if (pattern.count > 1) sort(workers, cascade + 1, pattern.start, i);
		//				pattern = { "", 0, 0 };
		//			}
		//		}
		//	}
		//}
		if ((cascade + 1) < SORT.attributes and SORT.status_list[(cascade + 1)]) {
			//cout << cascade << '\t' << SORT.status_list[(cascade + 1)] << endl;
			Pattern pattern = { "", 0, 1 };
			for (unsigned short i{ start }; i < end + 1; i++) {
				if (pattern.str == "") {
					pattern.str = concate_attributes(workers[i], cascade);
					//cout << pattern.str << endl;
					pattern.start = i;
				}
				else {
					if (pattern.str == concate_attributes(workers[i], cascade)) pattern.count++;
					else {
						if (pattern.count > 1) sort(workers, cascade + 1, pattern.start, i);
						pattern = { concate_attributes(workers[i], cascade), i, 1 };
					}
				}
			}
		}
	}
}


void sort_reset() {
	SORT.status = false;
	SORT.status_list = new bool[] { false, false, false, false, false, false, false };
	unsigned short cell = 0;
	SORT.birthday = { -1, Sort::type::NO_SORT };
	SORT.surname = { -1, Sort::type::NO_SORT };
	SORT.name = { -1, Sort::type::NO_SORT };
	SORT.nationality = { -1, Sort::type::NO_SORT };
	SORT.education = { -1, Sort::type::NO_SORT };
	SORT.id = { -1, Sort::type::NO_SORT };
	SORT.employed = { -1, Sort::type::NO_SORT };
};


void print(const worker* w) {
	unsigned short rows{ FILTER.rows };
	string title, line, sorts, body, menu;

	auto desc = [](const unsigned short item) {
		string info;
		if (item == 1 and SORT.birthday.cascade > -1) info = format("{}={}", SORT.birthday.cascade, SORT.desc[SORT.birthday.type]);
		else if (item == 2 and SORT.surname.cascade > -1) info = format("{}={}", SORT.surname.cascade, SORT.desc[SORT.surname.type]);
		else if (item == 3 and SORT.name.cascade > -1) info = format("{}={}", SORT.name.cascade, SORT.desc[SORT.name.type]);
		else if (item == 4 and SORT.nationality.cascade > -1) info = format("{}={}", SORT.nationality.cascade, SORT.desc[SORT.nationality.type]);
		else if (item == 5 and SORT.education.cascade > -1) info = format("{}={}", SORT.education.cascade, SORT.desc[SORT.education.type]);
		else if (item == 6 and SORT.id.cascade > -1) info = format("{}={}", SORT.id.cascade, SORT.desc[SORT.id.type]);
		else if (item == 7 and SORT.employed.cascade > -1) info = format("{}={}", SORT.employed.cascade, SORT.desc[SORT.employed.type]);
		return info;
		};


	title = format("\t{:^5}\t{:^10}\t{:^10}\t{:^8}\t{:^4}\t{:^4}\t{:^5}\t{:^10}", "Row", "Birthday", "Surname", "Name", "Nation", "Edu", "ID", "Employed");
	sorts = format("\t{:^5}\t{:^10}\t{:^10}\t{:^8}\t{:^4}\t{:^4}\t{:^5}\t{:^10}", "", desc(1), desc(2), desc(3), desc(4), desc(5), desc(6), desc(7));
	line = string(title.length() * 1.5, '_');
	menu = "MENU:\t1-NEXT\t2-FILTER\t3-SORT\t4-CREATE\t5-EDIT\t6-DEL\t> ";
	string footer(title.length() * 1.5, '=');

	cout << title << endl;
	if (SORT.status) cout << sorts << endl;
	cout << '\t' << line << endl;


	if (FILTER.begin == ROWS) FILTER.begin = 0;
	for (auto i{ FILTER.begin }; i < ROWS and rows; i++) {
		FILTER.begin += 1;
		if (w[i].row.filter) {
			rows--;
			cout << format("\t{:^5}\t{:^10}\t{:<10}\t{:<8}\t{:^4}\t{:^4}\t{:>5}\t{:^10}",
				w[i].row.num, w[i].birthday.date_str, w[i].surname, w[i].name, w[i].nationality, w[i].education, w[i].id, w[i].employed.date_str) << endl;
		}
	}
	cout << '\t' << footer << endl;
	cout << '\t' << menu;
}


worker* create(worker* old_data, unsigned short& rows) {
	//worker new_worker = Worker_New();
	worker new_worker;
	do {
		cout << "\tСтворення запису про нового працівника, введіть дату народження 'YYYY-mm-dd' ";
		cin >> new_worker.birthday.date_str;
	} while (!validator(new_worker.birthday.date_str));
	new_worker.birthday.date = date_convert(new_worker.birthday.date_str);
	cout << "\tСтворення запису про нового працівника, введіть прізвище ";
	cin >> new_worker.surname;
	cout << "\tСтворення запису про нового працівника, введіть ім'я' ";
	cin >> new_worker.name;
	cout << "\tСтворення запису про нового працівника, введіть національність ";
	cin >> new_worker.nationality;
	cout << "\tСтворення запису про нового працівника, введіть освіту ";
	cin >> new_worker.education;
	cout << "\tСтворення запису про нового працівника, введіть табельний номер ";
	cin >> new_worker.id;
	do {
		cout << "\tСтворення запису про нового працівника, введіть дату працевлаштування 'YYYY-mm-dd' ";
		cin >> new_worker.employed.date_str;
	} while (!validator(new_worker.employed.date_str));
	new_worker.employed.date = date_convert(new_worker.employed.date_str);


	char select;
	cout << "\tДодати нового працівника у файл(Y/y)? ";
	cin >> select;

	if (select == 'Y' or select == 'y') {
		string new_row;
		new_row = format("\n{}|{}|{}|{}|{}|{}|{}", new_worker.birthday.date, new_worker.surname, new_worker.name, new_worker.nationality, new_worker.education, new_worker.id, new_worker.employed.date);
		ofstream file(FILE, ios::app);
		if (file) file << new_row;
		file.close();
		worker* new_data = File_Read(FILE, ROWS);
		filter_reset(new_data);
		FILTER.begin = ROWS - FILTER.rows;
		return new_data;
	}
	return old_data;
}


worker* edit(worker* workers, unsigned short& rows) {
	string input;
	do {
		cout << "Вкажіть номер рядка, який ви хочете відредагувати: ";
		cin >> input;
	} while (validator(input, 'd'));

	const unsigned short row = stoi(input);

	worker* edit_worker = nullptr;

	for (auto w{ 0 }; w < rows and edit_worker == nullptr; w++) if (workers[w].row.num == row) edit_worker = &workers[w];

	bool status{ true };
	char select;
	do {
		cout << endl;
		cout << "\tІнформація про працівника" << endl;
		cout << format("\t1 {:<20}\t{}", "Дата народження", (*edit_worker).birthday.date_str) << endl;
		cout << format("\t2 {:<20}\t{}", "Прізвище", (*edit_worker).surname) << endl;
		cout << format("\t3 {:<20}\t{}", "Ім'я", (*edit_worker).name) << endl;
		cout << format("\t4 {:<20}\t{}", "Національність", (*edit_worker).nationality) << endl;
		cout << format("\t5 {:<20}\t{}", "Освіта", (*edit_worker).education) << endl;
		cout << format("\t6 {:<20}\t{}", "Табельний номер", (*edit_worker).id) << endl;
		cout << format("\t7 {:<20}\t{}", "Дата працевлаштування", (*edit_worker).employed.date_str) << endl;
		cout << "\tВиберіть, що ви хочете відредагувати? ";
		cin >> select;
		cout << endl;

		switch (select)
		{
		case '1':
			do {
				cout << "\tВведіть дату народження 'YYYY-mm-dd' ";
				cin >> (*edit_worker).birthday.date_str;
			} while (!validator((*edit_worker).birthday.date_str));
			(*edit_worker).birthday.date = date_convert((*edit_worker).birthday.date_str);
			break;
		case '2':
			cout << "\tВведіть прізвище ";
			cin >> (*edit_worker).surname;
			break;
		case '3':
			cout << "\tВведіть ім'я' ";
			cin >> (*edit_worker).name;
			break;
		case '4':
			cout << "\tВведіть національність ";
			cin >> (*edit_worker).nationality;
			break;
		case '5':
			cout << "\tВведіть освіту ";
			cin >> (*edit_worker).education;
			break;
		case '6':
			cout << "\tВведіть табельний номер ";
			cin >> (*edit_worker).id;
			break;
		case '7':
			do {
				cout << "\tВведіть дату працевлаштування 'YYYY-mm-dd' ";
				cin >> (*edit_worker).employed.date_str;
			} while (!validator((*edit_worker).employed.date_str));
			(*edit_worker).employed.date = date_convert((*edit_worker).employed.date_str);
			break;
		default: status = false; break;
		}
	} while (status);
	cout << "\tРедагування закінчено" << endl;

	ofstream file(FILE, ios::trunc);
	if (file) {
		for (auto r{ 0 }; r < ROWS; r++) {
			file << format("{}{}{}{}{}{}{}{}{}{}{}{}{}",
				workers[r].birthday.date, DELIMITER, workers[r].surname, DELIMITER, workers[r].name, DELIMITER, workers[r].nationality, DELIMITER, workers[r].education, DELIMITER, workers[r].id, DELIMITER, workers[r].employed.date);
			file << ((r + 1 == ROWS) ? "" : "\n");
		}
		file.close();
		worker* new_data = File_Read(FILE, ROWS);
		filter_reset(new_data);
		FILTER.begin = ROWS - FILTER.rows;
		return new_data;
	}
}


worker* del(worker* w, unsigned short& rows) {
	string dl;
	cout << format("\tВведіть список номерів рядків, які ви хочете видалити ({} - розделитель, EXIT - exit) ", DELIMITER);
	cin >> dl;

	if (dl != "EXIT") {
		unsigned short count{ 1 };
		for (auto d : dl) if (d == DELIMITER) count++;
		string* del_list = split(dl);
		unsigned short* del_list_rows = new unsigned short[count];
		for (auto i{ 0 }; i < count; i++) del_list_rows[i] = stoi(del_list[i]);

		for (auto r{ 0 }; r < ROWS; r++) {
			w[r].row.del = false;
			for (auto i{ 0 }; i < count; i++) if (w[r].row.num == del_list_rows[i]) w[r].row.del = true;
		}

		ofstream file(FILE, ios::trunc);
		if (file) {
			for (auto r{ 0 }; r < ROWS; r++)
				if (!w[r].row.del) {
					file << format("{}{}{}{}{}{}{}{}{}{}{}{}{}",
						w[r].birthday.date, DELIMITER, w[r].surname, DELIMITER, w[r].name, DELIMITER, w[r].nationality, DELIMITER, w[r].education, DELIMITER, w[r].id, DELIMITER, w[r].employed.date);
					file << ((r + 1 == ROWS) ? "" : "\n");
				}
			file.close();
			delete[] del_list, del_list_rows;

			worker* new_data = File_Read(FILE, ROWS);
			filter_reset(new_data);
			FILTER.begin = ROWS - FILTER.rows;
			return new_data;
		}
	}




	/*for (auto i{ 0 }; i < ROWS; i++) w[i].row.flag = false;

	for (auto i{ 0 }; i < count; i++) {
		for (unsigned short wi{ FILTER.begin }, r{ 0 }; wi < rows and r < FILTER.rows; w++)
			cout << format("\t{:^5}\t{:^10}\t{:<10}\t{:<8}\t{:^4}\t{:^4}\t{:>5}\t{:^10}",
				w[wi].row.num, w[wi].birthday.date_str, w[wi].surname, w[wi].name, w[wi].nationality, w[wi].education, w[wi].id, w[wi].employed.date_str) << endl;
	}*/

	return w;
}


string* gen_data(const unsigned short count) {
	cout << "GENERATE DATA:" << endl;
	string alphabet{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	srand(time(NULL));

	auto rnd = [](const unsigned short min, const unsigned short max) {
		return (rand() % (max - min + 1) + min);
		};

	//worker* arr = new worker[count];
	string* arr = new string[count];

	// test worker
	worker test;
	for (unsigned short c{ 0 }; c < count; c++) {
		test.row.num = c;
		test.birthday.date = rnd(7310, 16200);
		test.surname = "";
		for (size_t letter{ 0 }; letter < 3; letter++) test.surname += alphabet[rnd(0, 5)];
		test.name = "";
		for (size_t letter{ 0 }; letter < 2; letter++) test.name += alphabet[rnd(0, 5)];
		test.nationality = alphabet[rnd(0, 3)];
		test.education = alphabet[rnd(0, 3)];
		test.id = rnd(1, 10000);
		test.employed.date = test.birthday.date + rnd(6580, 7200);
		arr[c] = format("{}|{}|{}|{}|{}|{}|{}|{}", test.row.num, test.birthday.date, test.surname, test.name, test.nationality, test.education, test.id, test.employed.date); //// !!!!
		cout << arr[c] << endl;
	}
	return arr;
}


void test() {
	cout << "TESTING:" << endl;
	cout << DELIMITER << endl;
	const short ly[]{ 1959, 1960, 1961, 1900, 1984, 2000 };
	for (auto i : ly) cout << format("test isLeapYear {}= {}", i, isLeapYear(i)) << endl;

	const string valid[]{ "1959-12-01", "1960-01-01", "1970-01-01", "2000-01-01", "2011-01-01", "2011-00-01", "2011-01-00", "2011-01-32", "2045-12-31" };
	for (auto i : valid) cout << format("test validator {}= {}", i, validator(i)) << endl;

	for (auto i : valid) cout << format("\ttest date_convert str {}= {}", i, date_convert(i)) << endl;

	const int dcn[]{ 14661, 14900, 8469, 12558, 19409 };
	for (auto i{ 0 }; i < 5; i++) cout << format("test date_convert short {}= {}", dcn[i], date_convert(dcn[i])) << endl;

	const short count_gen{ 10 };
	string* split_return;
	string* test_data = gen_data(count_gen);
	for (auto t{ 0 }; t < count_gen; t++) {
		cout << test_data[t] << '\t';
		split_return = split(test_data[t]);
		for (auto sr{ 0 }; sr < 8; sr++) cout << split_return[sr] << '\t';
		cout << endl;
	}
	delete[] split_return, test_data;
	cout << "END TEST" << endl;
}
