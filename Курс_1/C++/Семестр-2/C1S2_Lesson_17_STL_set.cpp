#include <windows.h>
#include <iostream>
#include <format>
#include <string>
#include <set>

#include <list>
#include <utility> // for std::pair


using namespace std;



int main()
{
    SetConsoleOutputCP(1251);


    set<short> mySet1{ 1,2,3,4,5,100 };
    //for (auto i{ 0 }; i < 20; i++) mySet1.insert(rand() % 10);
    for (auto& i : mySet1) cout << i << '\t';
    cout << endl;
    set<short> mySet2{ 1,2,3,4,6 };
    //for (auto i{ 0 }; i < 20; i++) mySet2.insert(rand() % 12);
    for (auto& i : mySet2) cout << i << '\t';

    cout << endl;

    cout << (mySet1 == mySet2) << endl;
    cout << (mySet1 < mySet2) << endl;
    cout << (mySet1 > mySet2) << endl;


    auto it = mySet1.find(3); // возвращает итератор
    cout << *it << endl;

    if (mySet1.find(99) != mySet1.end()) cout << true << endl;
    else cout << false << endl;
    //for (set<short>::const_iterator i; i != it; i++) cout << *i << endl;
    cout << endl;

    {
        cout << "erase: " << endl;
        set<short> mySet3{ 20,6,3,9,2,8,7,30,28,35,32,34,25,29 };
        //for (auto i{ 0 }; i < 20; i++) mySet3.insert(rand() % 10);
        for (auto& i : mySet3) cout << i << '\t';
        cout << endl;
        auto result_erase = mySet3.erase(28); // return size_t 0 / 1    

        for (auto& i : mySet3) cout << i << '\t';
        cout << endl;

        auto result_insert = mySet3.insert(1); // return (iterator, bool)
        cout << format("result_insert: secont {}\t{}", "iterator", result_insert.second) << endl;
        cout << endl;
    }

    set<short, string> mySet4;
    //mySet4.emplace(1, "A");
    //for (auto& m : mySet4) cout << format("{}\t{}", m.first) << endl;

    {
        cout << "multiset" << endl;
        multiset<int> myMultiSet = { 1,1,66,16,48,99 };
        for (auto& ms : myMultiSet) cout << ms << '\t';
        cout << endl;
        auto it1 = myMultiSet.lower_bound(1); // найдет 1
        auto it2 = myMultiSet.upper_bound(1); // первое после 1 число для отсортированного сета (16)
        auto it3 = myMultiSet.equal_range(1);

        cout << endl;
    }


    /////////////////////

    {
        typedef short aaa;
        aaa dd[5];
    }

    
    typedef tuple<short, string> data; // переименованный тит данных...
    //set<data> mySet;
    //for (auto i{ 0 }; i < 20; i++) mySet.insert(data(rand() % 10, "AAA"));

    {
        list<pair<short, string>> test1;
        test1.emplace_back(1, "AAA");
        for (const auto& t : test1)  cout << format("{}\t{}", t.first, t.second) << endl;

        list<pair<short, string>> test2;
        test2.emplace_back(1, "AA");
        for (const auto& t : test2)  cout << format("{}\t{}", t.first, t.second) << endl;

        cout << "test1 == test2 " << (test1 == test2) << endl;
        cout << "test1 > test2 " << (test1 > test2) << endl; // !!
        cout << "test1 < test2 " << (test1 < test2) << endl; // !!
        cout << "AAA > AA " << ("AAA" > "AA") << '\t' << "AAA < AA " << ("AAA" < "AA") << endl;
    }


    return 0;
}


