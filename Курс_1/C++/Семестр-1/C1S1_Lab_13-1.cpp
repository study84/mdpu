// Даний масив символів, серед яких є символ двокрапки ':'. Визначити, скільки символів передує.

#include <windows.h> 
#include <iostream>
//#include <format>

using namespace std;

int main()

{
    SetConsoleOutputCP(1251);

    const int size = 10; // довжина рядка
    char txt[size];
    char symbol{ ':' }; // шуканий символ
    int index{-1}; // ознака виявлення символу

    cout << "введите текст(содержащий символ ':') ";
    cin.getline(txt, size, '\n');

    for (int letter{ 0 }; letter < size; letter++) {
        if (txt[letter] == symbol)
            index = letter;
    }
    
    if (index > -1) cout << "символу " << symbol << " передує " << index << endl;
    else cout << "вказаний символ " << symbol << " не знайдено!" << endl;
    

    return 0;
}

