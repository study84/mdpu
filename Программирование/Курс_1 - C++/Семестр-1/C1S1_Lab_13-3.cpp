// 8. Введіть два масиви символів. Визначити, чи вони є анаграмами, тобто один рядок отриманий з іншого перестановкою букв. Наприклад, рядки "БУК" та "КУБ" є анаграмами.
#include <windows.h>
#include <iostream>
#include <format>


using namespace std;

int main()

{
    SetConsoleOutputCP(1251);    

    const int size{ 7 };    
    char txt1[size];
    char txt2[size];
    bool anagram{true};

    cout << format("введіть слово 1 ({} символів) ", size - 1);
    cin.getline(txt1, size, '\n');
    cout << endl;
    cout << format("введіть слово 2 ({} символів) ", size - 1);
    cin.getline(txt2, size, '\n');
    cout << endl;

    for (int l1{ 0 }, l2{size - 2}; l1 < size - 1; l1++, l2--) {
        //cout << format("{} {}\t{} {}\t{}", l1, txt1[l1], l2, txt2[l2], txt1[l1] == txt2[l2]) << endl;
        if (txt1[l1] != txt2[l2]) anagram = false;
    }

    cout << format("слово 1 і слово 2 {}є анаграмами", anagram ? "" : "не ");

    return 0;
}

