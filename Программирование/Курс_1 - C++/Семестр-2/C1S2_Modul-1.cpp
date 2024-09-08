// 823-і_Золотухін_Андрій_Олександрович

#include <windows.h>
#include <iostream>
#include <string>
#include <format>

using namespace std;

bool anagrams(string word1, string word2);
int pow(int num, size_t extent);

int main()
{
    SetConsoleOutputCP(1251);
	cout << "823-і_Золотухін_Андрій_Олександрович. Варіант 8" << endl;
	

    cout << "Завдання 1: Напишіть програму на C++, яка отримує на вхід два символьних масиви і перевіряє, чи є вони анаграмами." << endl;
    string word1{ "sileNt" };
    string word2{ "liSten" };
    cout << format("{}\t{}\t{}", word1, word2, anagrams(word1, word2)) << endl;


    cout << "Завдання 2: Напишіть програму на C++, яка створює динамічний масив цілих чисел, пропонує користувачеві ввести елементи, а потім виводить на екран добуток елементів" << endl;
    size_t size;
    cout << "Введіть розмір масиву ";
    cin >> size;
    int* array = new int[size];
    int product{ 1 };
    for (size_t i; i < size; i++) {
        cout << "введіть елемент " << i + 1 << ": ";
        cin >> array[i];
        product *= array[i];
    }
    cout << "добуток елементів " << product << endl;


    cout << "Завдання 3: Напишіть програму на C++, яка визначає функцію для обчислення степеня числа. Функція повинна отримувати два цілочисельних аргументи (основу і показник степеня) і повертати результат піднесення основи до степеня" << endl;
    int num; size_t extent;
    cout << "введіть число ";
    cin >> num;
    cout << "введіть ступінь числа " << num << ": ";
    cin >> extent;
    cout << num << " у ступені " << extent << " = " << pow(num, extent);

    return 0;
}


bool anagrams(string word1, string word2) {
    bool status{ false };
    //word1 = tolower(word1);

    if (word1.length() == word2.length()) {
        for (size_t l1{ 0 }; l1 < word1.length(); l1++) {
            word1[l1] = tolower(word1[l1]);
            word2[l1] = tolower(word2[l1]);
        }        

        for (size_t l1{0}; l1 < word1.length() - 1; l1++)
            for (size_t l2{ l1 }; l2 < word1.length(); l2++) {
                if (word1[l1] > word1[l2 + 1]) swap(word1[l1], word1[l2 + 1]);
                if (word2[l1] > word2[l2 + 1]) swap(word2[l1], word2[l2 + 1]);
            }
        //cout << word1 << endl;
        //cout << word2 << endl;
        if (word1 == word2) status = true;
    }

    return status;
}


int pow(int num, size_t extent) {
    if (extent == 0)
        return 1;
    else {
        int num2{ num };
        for (size_t i{ 0 }; i < extent - 1; i++) num2 *= num;
        return num2;
    }
}