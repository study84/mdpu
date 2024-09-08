/*
Контейнер queue реалізує механізм зберігання через адаптер, що працює за принципом "першим увійшов - першим вийшов"
*/


#include <windows.h>
#include <iostream>
#include <queue>

#include <string>


#include <algorithm> // fro sort
#include <numeric> // accumulate


using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    
    queue<unsigned short> tqueue;

    string input;
    do {
        cout << "Menu: 1=add, 2=get: ";
        getline(cin, input, '\n');
        if (input == "1") {
            getline(cin, input, '\n');
            tqueue.push(stoi(input));
        }
        else if (input == "2") {
            cout << (tqueue.front()) << endl;
            tqueue.pop();
        }

        //for (auto& t : tqueue) cout << t << '\t';

    } while (!tqueue.empty() && !input.empty()); // or getline(cin, input)


    
    

    


    
    

    return 0;
}
