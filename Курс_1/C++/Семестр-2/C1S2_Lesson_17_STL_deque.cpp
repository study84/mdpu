#include <windows.h>
#include <iostream>
#include <deque>

#include <algorithm> // fro sort
#include <numeric> // accumulate


using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    
    deque<int>data; // Объявление двунакправленного списка
    deque<int>::iterator iter;
    deque<int>::reverse_iterator riter;

    // ?.push_back(value); // добавить в конец списка
    // ?.push_front(value); // добавить в начало списка

    cout << " Введіть послідовність ненульових цілих чисел, " << "розділених пробілами. Для завершення введіть 0." << endl;
    int value(0);

    while (cin >> value) data.push_back(value); // добавить в конец списка
    for (iter = data.begin(); iter != data.end(); iter++) cout << *iter << '\t';
    cout << endl;

    for (riter = data.rbegin(); riter != data.rend(); riter++) cout << *riter << '\t';
    cout << endl;

    sort(data.begin(), data.end());

    for (iter = data.begin(); iter != data.end(); iter++) cout << *iter << '\t';
    cout << endl;

    accumulate(data.begin(), data.end(), 0);

    iter = data.begin();
    advance(iter, 3);    
    cout << *iter << endl;

    iter = data.begin();
    data.insert(iter, 10000);
    for (iter = data.begin(); iter != data.end(); iter++) cout << *iter << '\t';
    cout << endl;
    
    
    cout << data.size() << endl;
    

    return 0;
}
