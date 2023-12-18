// (Легкий) Напишіть функцію на C++, яка отримує символьний аргумент і повертає true, якщо це голосна, і false у протилежному випадку.

#include <windows.h>
#include <iostream>
#include <format>

using namespace std;

bool type_letter(char letter);

int main()

{
    SetConsoleOutputCP(1251);    

    const int size{ 2 };    
    char txt[size];    

    cout << format("введіть букву (прописну) ");
    cin.getline(txt, size, '\n');

    cout << format("{} = {}", txt[0], type_letter(txt[0]));

    return 0;
}


bool type_letter(char letter) {
    switch (letter) {
        case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
            return true; break;
        default: return false; break;
    }
}