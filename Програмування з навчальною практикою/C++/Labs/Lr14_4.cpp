// завдання розв'язати не вдалося, зважаючи на поки що не ясні способи програмування на с++ викладено алгоритм у загальних рисах

// (Дуже складно) Напишіть функцію мовою C++, яка отримує в якості аргументів символьний масив та його розмір і повертає новий масив, що містить довжину найдовшого спільного підрядка вихідного масиву та його зворотний розмір.


#include <windows.h>
#include <iostream>
#include <format>

using namespace std;

void numeration(char symbol, int offset, int index, char* pattern_symbols, int* pattern_offset);

void abmh(char* txt, int txt_size, char* pattern, int pattern_size);

int main()
{
    SetConsoleOutputCP(1251);

    cout << "ТЗ" << endl;

    const int size{ 20 }; // враховувати останній символ '\n'
    //char text[size];
    char text[]{ "as for asddsa werew" };
    char text_revers[size - 1];    

    cout << format("введіть речення ({} букв) ", size - 1);
    //cin.getline(text, size, '\n');
    
    // реверс рядка
    cout << endl;
    for (int i{ size - 2 }, r{ 0 }; i >= 0; i--, r++) {
        text_revers[r] = text[i];
        cout << text_revers[r];
    } 

    // нарізка фрагментів
    for (int i1{ 0 }; i1 < size; i1++)
        for (int i2{ i1 + 1 }; i2 < size; i2++) {
            //
            for (int i3{ i1 }; i3 < i2; i3++)
                1;
                //cout << text_revers[i3];
            //cout << endl;
        }
    ////////////////////////////////

    char test_text[]{ "большие метеоданные" };
    char test_pattern[]{ "данные" };    
    
    int text_size = sizeof test_text / sizeof test_text[0];
    int pattern_size = sizeof test_pattern / sizeof test_pattern[0];
    cout << format("\n'{}' size={}", test_text, text_size) << endl;
    
    abmh(test_text, text_size, test_pattern, pattern_size);

    return 0;

}


void numeration(char symbol, int offset, int index, char* pattern_symbols, int* pattern_offset) {
    // крок 1. створення таблиці зміщень
    const int size = sizeof pattern_symbols / sizeof pattern_symbols[0];
    for (int i{ 0 }; i < size; i++)
        if (symbol == *(pattern_symbols + i)) {
            offset = *(pattern_offset + i);
            break;
            //goto next;
        }
    *(pattern_symbols + index) = symbol;
    //next:
    *(pattern_offset + index) = offset;
}



void abmh(char* txt, const int txt_size, char* pattern, const int pattern_size) {
    // Алгоритм Бойєра-Мура-Хорспула
    // https://ru.wikipedia.org/wiki/Алгоритм_Бойера_—_Мура_—_Хорспула
    
    

    //const int size_pattern = sizeof pattern / sizeof *(pattern + 1) - 2;    
    //cout << format("\n'{}' size={}", pattern, size_pattern) << endl;
    char pattern_symbols[pattern_size];
    int pattern_offset[pattern_size + 1];

    for (int p{ pattern_size - 2 }, os{ 1 }; p >= 0; p--, os++)
        numeration(pattern[p], os, p, pattern_symbols, pattern_offset);
    numeration(pattern[pattern_size - 1], pattern_size, pattern_size - 1, pattern_symbols, pattern_offset);

    //cout << endl;
    //for (int i{ 0 }; i < size; i++)
    //    cout << format("{}\t{}\t{}", i, pattern[i], pattern_offset[i]) << endl;
    //cout << endl;
    //for (int i{ 0 }; i < size; i++)
    //    cout << format("{}\t{}\t{}", i, pattern_symbols[i], pattern_offset[i]) << endl;

    const int size_txt = sizeof txt / sizeof *(txt + 0); // 20
    cout << format("\n'{}' size={} ?=20", txt, size_txt) << endl;
    

}