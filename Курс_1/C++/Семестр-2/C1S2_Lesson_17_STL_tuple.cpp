/*
стек є механізм зберігання, що працює за принципом " останнім увійшов - першим вийшов", в якому в кожен момент часу доступний лише об'єкт, щойно вставлений в стек .
*/


#include <windows.h>
#include <iostream>
#include <stack>
#include <list>
#include <array>

//#include <tuple>

#include <string>
#include <format>


#include <algorithm> // fro sort
#include <numeric> // accumulate


using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    
    typedef tuple <int, string, string, int> Record;

    array<Record, 5> personnel = { Record(1001,"Joan", "Jetson", 35), Record(1002, "Jim", "Jones", 26), Record(1003, "June", " Jello ", 31), Record(1004, "Jack", "Jester", 39) };

    for (auto& p : personnel) cout << get<0>(p) << endl;
    
    typedef tuple <> Record2;

    size_t size = tuple_size<Record2>::value;


    
    

    return 0;
}
