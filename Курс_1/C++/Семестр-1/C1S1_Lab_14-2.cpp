// (Середній) Напишіть функцію на C++, яка приймає символьний масив та його розмір як аргументи і повертає true, якщо масив є паліндромом, і false у протилежному випадку.

#include <windows.h>
#include <iostream>
#include <format>

using namespace std;

bool palindrome(char word[], int size);

int main()

{
    SetConsoleOutputCP(1251);    

    const int size{ 10 };
    char word[size];    

    cout << format("введіть слово ({} букв) ", size - 1);
    cin.getline(word, size, '\n');

    cout << format("це слів {}є паліндромо", palindrome(word, size) ? "":"не ");    

    return 0;
}


bool palindrome(char word[], int size) {
    bool palindrome_test{ true };
    //cout << size << endl;
    for (int l1{ 0 }, l2{ size - 2 }; l1 < (size - 1) / 2; l1++, l2--) {
        //cout << format("{} {}\t{} {}", l1, word[l1], l2, word[l2]) << endl;
        if (word[l1] != word[l2]) {
            palindrome_test = false;
            break;
        }
    }
    //cout << palindrome_test << endl;
    return palindrome_test;
}