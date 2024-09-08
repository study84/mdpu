#include <windows.h>
#include <iostream>
#include <list>
#include <string>

#include <algorithm> // fro sort
#include <numeric> // accumulate


using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    
    list<string> names;
    list<string> sayings(20, "AAA");

    cout << names.size() << endl;
    cout << sayings.size() << endl;

    size_t c{0};
    for (auto& s : sayings) s = (string(++c, 'A'));
    
    for (const auto& s : sayings) cout << s << endl;


    list<string>::iterator lit = sayings.begin();
    advance(lit, 6); // Перемещаем итератор вперед на 6 элементов
    cout << *lit << endl;

    const size_t size{ sayings.size() };
    for (auto i{ 0 }; i < size; i++) sayings.push_back((string(++c, 'A')));

    for (const auto s : sayings) cout << s << endl;

    cout << "Певый элеент\t" << sayings.front() << endl;
    cout << "Последний элеент\t" << sayings.back() << endl;
    //////////////////////////////

    list<string> text;
    list<string>::iterator iter; // Зберігає ітератор
    // Читає дані
    cout << " Введіть кілька рядків тексту." << "Для завершення натисніть клавішу < Enter>:" << endl;
    string sentence;    
    while (getline(cin, sentence, '\n'), !sentence.empty())  text.push_back(sentence);

    text.sort();

    for (auto t : text) cout << t << endl;


    list<int> list1 = { 1, 2, 3 };
    list<int> list2 = { 4, 5, 6 };

    list1.splice(list1.begin(), list2);
    for (auto l : list1) cout << l << '\t';


    
    list<int> mylist = { 1, 2, 3, 4, 5, 6, 2, 3, 4, 1 };
    mylist.unique(); // только после сортировки
    for (auto& l : mylist) cout << l << '\t';
    

    return 0;
}
