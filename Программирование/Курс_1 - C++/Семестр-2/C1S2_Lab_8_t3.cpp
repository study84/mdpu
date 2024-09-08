#include <windows.h>
#include <iostream>
#include <format>
#include <string>
//#include <iomanip>

using namespace std;

// зворотний порядок +
// статус паліндрому -
// кількість входжень заданого підрядка
// кількість входжень кожного символу відповідно


void func(const string text, const string find);


int main()
{
    SetConsoleOutputCP(1251);

    cout << "Варіант 8" << endl;

    func("AaaBbCcc", "a");


    return 0;
}


void func(const string str, const string substr) {
    string text_revers, txt, txt_revers, symbols_unique;
    
    // зворотний порядок
    // статус паліндрому
    for (auto s : str) {
        text_revers.insert(0, 1, s); // зворотний порядок +
        txt += tolower(s);
        txt_revers.insert(0, 1, tolower(s));

        if (symbols_unique.find(s) == string::npos) symbols_unique += s; // кількість входжень кожного символу відповідно: рядок-список унікальних символів
    }
    cout << "зворотний порядок: " << text_revers << endl;
    cout << "статус паліндрому: " << (txt == txt_revers) << endl;


    // кількість входжень заданого підрядка
    short index{ 0 }, count_substr{ 0 };
    while ((index = str.find(substr, index)) != string::npos) {
        count_substr++;
        index += substr.length();
    }
    cout << format("кількість входжень заданого підрядка: {}", count_substr) << endl;


    //кількість входжень кожного символу відповідно
    
    cout << format("унікальні символи: '{}'", symbols_unique) << endl; // друк рядок-список унікальних символів

    size_t size{ symbols_unique.length() }; // змінна, довжини рядка = кол-ву унікальних символів
    
    short* symbols = new short[size]; // створення динамічного масиву
    for (size_t s{ 0 }; s < size; s++) symbols[s] = 0; // обнулення значень масиву
    for (size_t s{ 0 }; s < size; s++) cout << symbols[s] << '\t'; // друк значень масиву
    cout << endl;

    for (auto s : str) symbols[symbols_unique.find(s)] += 1; // підрахунок кількості входжень унікальних символів у рядок
    for (size_t s{ 0 }; s < size; s++) cout << symbols[s] << '\t'; // друк кількості входжень унікальних символів у рядок символів

}