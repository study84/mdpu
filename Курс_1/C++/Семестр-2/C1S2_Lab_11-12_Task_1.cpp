#include <windows.h>
#include <iostream>
#include <string>
#include <format>
#include <regex>

using namespace std;


struct TRAIN {
    unsigned short train_index;
    string name_point;    
    unsigned short departure_time;
};

enum type { TEST, TIME, INDEX };

string TITLE = "Номер\tІндекс\tПункт призначення\tЧас відправлення";


TRAIN* create_trains(const unsigned count); // Створення масиву потягів
bool time_format_test(string str_time); // перевірка формату часу
int convert_time(string time); // конвектор часу число - рядок
string convert_time(int time); // конвектор часу рядок - число
void print(TRAIN* trains, const size_t count); // друк опису потягів
void filter(TRAIN* trains, const size_t count, const type property); // друк опису потягів


int main()
{   
    SetConsoleOutputCP(1251);   

    unsigned short count;
    cout << "Введіть кількість поїздів: ";
    cin >> count;

    TRAIN* trains = create_trains(count);

    print(trains, count);

    filter(trains, count, TEST);

    cout << "Варіант 7:  виведення на екран інформації про поїзди, що відправляються після введеного з клавіатури часу" << endl;
    filter(trains, count, TIME);
    
    cout << "Варіант 8: виведення  на  екран  інформації  про  пункт  призначення,  до  якого відправляється поїзд, номер якого запроваджено з клавіатури" << endl;
    filter(trains, count, INDEX);
    
    delete[] trains;
    
    

    return 0;
}


TRAIN* create_trains(const unsigned count) {
    static TRAIN* trains = new TRAIN[count];

    char gen_trains;
    cout << "Генерувати потяги автоматично (Y/n) ";
    cin >> gen_trains;    

    if (gen_trains == 'Y' or gen_trains == 'y') {
        srand(time(NULL));        

        auto rnd = [](const unsigned short min, const unsigned short max) {            
            //if (min > max) swap(min, max);
            return (rand() % (max - min + 1) + min);
        };

        auto name = [](const unsigned short len) {
            //char alphabet[]{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
            string name{""};            
            for (size_t l{ 0 }; l < len; l++) name.insert(0, 1, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % (25 - 0 + 1)]); // не можна використовувати вищеописану лямбда-функцію
            return name;
        };
        

        for (size_t t{ 0 }; t < count; t++) {
            trains[t].train_index = rnd(1, count * 10); // генерація індексу потяга
            trains[t].name_point = name(rnd(3, 10)); // генерація пункту призначення
            trains[t].departure_time = rnd(1, 1439); // генерація часу відправлення
        }
    }
    else {
        string enter_time;
        for (size_t train{ 0 }; train < count; train++) {
            cout << format("Введіть номер потяга {} ", train);
            cin >> trains[train].train_index;
            cout << format("Введіть пункт призначення для потяга {}({}) ", train, trains[train].train_index);
            cin >> trains[train].name_point;
            while (true) {
                cout << format("Введіть час відправлення поїзда {} (формат години:хвилини) ", train);
                cin >> enter_time;
                if (time_format_test(enter_time)) {
                    trains[train].departure_time = convert_time(enter_time);
                    enter_time = "";
                    break;
                }
                else cout << format("ПОМИЛКА ФОРМАТУ ЧАСУ '{}' !!!", enter_time) << endl;

            }
        }
    }    
    //print(trains, count);

    return trains;
}


bool time_format_test(string str_time) {
    regex pattern("\\b([01]?[0-9]|2[0-3]):([0-5]\\d)\\b");
    return regex_match(str_time, pattern);
}


int convert_time(string str_time) {
    short minute{ -1 };
    if (time_format_test(str_time)) minute = stoi(str_time.substr(0, str_time.find(':'))) * 60 + stoi(str_time.substr(str_time.find(':') + 1));
    return minute;
}


string convert_time(int time) {
    string str_time;
    short h{ 0 }, m{ 0 };
    h = time / 60;
    m = time % 60;
    str_time = format("{}:{}{}", h, (m < 10 ? "0":""), m);
    //cout << h << '\t' << m << '\t' << str_time << endl;    
    return str_time;
}


void print(TRAIN* trains, const size_t count) {
    cout << TITLE << endl;
    for (size_t t{ 0 }; t < count; t++) cout << format("{:>4}\t{:>4}\t{:<17}\t{:>5}", t + 1, trains[t].train_index, trains[t].name_point, convert_time(trains[t].departure_time)) << endl;
}


void filter(TRAIN* trains, const size_t count, const type property) {
    bool status{ false };    
    switch (property)
    {
        case TIME: {
            string enter_time;
            short time{ -1 };
            while (true) {
                cout << "Введіть критерій часу відправлення поїзда (формат години:хвилини) ";
                cin >> enter_time;
                if (time_format_test(enter_time)) {
                    cout << endl;
                    cout << TITLE << endl;
                    time = convert_time(enter_time);
                    for (size_t t{ 0 }; t < count; t++)
                        if (trains[t].departure_time > time) {
                            status = true;
                            cout << format("{:>4}\t{:>4}\t{:<17}\t{:>5}", t + 1, trains[t].train_index, trains[t].name_point, convert_time(trains[t].departure_time)) << endl;
                        }
                    if (!status) cout << "НЕ ЗНАЙДЕНО ПОТЯГА, ЩО ВІДПОВІДАЄ ЗАДАНИМ КРИТЕРІЯМ ЧАСУ" << endl;
                    break;
                }
            }
        } break;

        case INDEX: {
            unsigned short index;
            cout << "Введіть індекс потяга ";
            cin >> index;
            cout << endl;
            cout << TITLE << endl;
            for (size_t t{ 0 }; t < count; t++)
                if (trains[t].train_index == index) {
                    status = true;
                    cout << format("{:>4}\t{:>4}\t{:<17}\t{:>5}", t + 1, trains[t].train_index, trains[t].name_point, convert_time(trains[t].departure_time)) << endl;
                }
            if (!status) cout << "НЕ ЗНАЙДЕНО ПОТЯГА, ЩО ВІДПОВІДАЄ ЗАДАНИМ КРИТЕРІЯМ ІНДЕКСУ" << endl;
            break;
        } break;

        default: cout << "ЗАЗНАЧЕНИЙ ПАРАМЕТР НЕ ЗАЙДЕНИЙ" << endl; break;
    }
}