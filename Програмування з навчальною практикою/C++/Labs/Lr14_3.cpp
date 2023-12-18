// (Складно)Напишіть функцію мовою C++, яка отримує масив символів та його розмір як аргументи і повертає новий масив, що містить довжину найдовшого паліндромного підрядка, який починається з кожного індексу вихідного масиву.
// завдання було зрозуміло так, що потрібно вивести найдовший паліндром !
// без використання посилань і вказівників!

#include <windows.h>
#include <iostream>
#include <format>

using namespace std;

int palindrome_max[3]; // start, stop, size

void sentence_parsing(char txt[], int size);
bool palindrome(char txt[], int start, int stop);

int main()
{
    SetConsoleOutputCP(1251);

    const int size{ 20 }; // враховувати останній символ '\n'
    char text[size];
    //char text[]{ "as fdr asddsa werew" };

    cout << "(Складно)Напишіть функцію мовою C++, яка отримує масив символів та його розмір як аргументи і повертає новий масив, що містить довжину найдовшого паліндромного підрядка, який починається з кожного індексу вихідного масиву." << endl;
    cout << "завдання було зрозуміло так, що потрібно вивести найдовший паліндром !" << endl;
    cout << "без використання посилань і вказівників!" << endl;

    cout << format("введіть речення ({} букв) ", size - 1);
    cin.getline(text, size, '\n');    
        
    sentence_parsing(text, size);
    for (int i{ palindrome_max[0] }; i < palindrome_max[1]; i++)
        cout << text[i];   

    return 0;
}


void sentence_parsing(char txt[], int size) {
    int start{ 0 }, stop{ 0 };    

    for (int i{ 0 }; i < size; i++) {        
        if (txt[i] == ' ' or txt[i] == '\0') {
            stop = i;
            palindrome(txt, start, stop);            
            start = i + 1;
        }
    }
}


bool palindrome(char txt[], int start, int stop) {
    bool palindrome_flag{ false };
    for (int str{ start }, stp{ stop - 1 }; str < stp; str++, stp--)
        if (txt[str] != txt[stp])
            goto exit;

    palindrome_flag = true;
    if (palindrome_max[2] < stop - start) {
        palindrome_max[0] = start;
        palindrome_max[1] = stop;
        palindrome_max[2] = stop - start;
    }

    exit:
    return palindrome_flag;
}