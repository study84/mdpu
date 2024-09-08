/*
стек є механізм зберігання, що працює за принципом " останнім увійшов - першим вийшов", в якому в кожен момент часу доступний лише об'єкт, щойно вставлений в стек .
*/


#include <windows.h>
#include <iostream>
#include <stack>
#include <list>

#include <string>
#include <format>


#include <algorithm> // fro sort
#include <numeric> // accumulate


using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    
    stack<unsigned short> tstack;

    string input;
    do {
        cout << format("Size={}\tMenu: 1=add, 2=get, 3=get all: ", tstack.size());
        getline(cin, input, '\n');
        if (input == "1") {
            getline(cin, input, '\n');
            tstack.push(stoi(input));
        }
        else if (input == "2") {
            cout << (tstack.top()) << endl;
            tstack.pop();
        }
        else if (input == "3") {
            for (auto i{ 0 }; !tstack.empty(); i++) {
                cout << tstack.top() << '\t';
                tstack.pop();
            }
            cout << endl;
        }       

    } while (!tstack.empty() && !input.empty()); // or getline(cin, input)


    
    stack<int> tstack2;
    for (auto i{ 0 }; i < 10; i++) tstack2.push(i);
    auto t = tstack2._Get_container(); // получаем тип контейнера и далее можем работать с ним....
    cout << t[0] << '\t' << tstack2.top() << endl;

    stack<int, list<int>> tstack3; // указаываем 1 из 3 типов контейнеров для стека vecto / deque / list    
    

    return 0;
}
