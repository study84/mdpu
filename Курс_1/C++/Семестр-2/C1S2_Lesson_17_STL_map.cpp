#include <windows.h>
#include <iostream>
#include <format>
#include <string>

#include <map>
//#include <utility> // for std::pair

#include <list>
#include <set>


using namespace std;



int main()
{
    SetConsoleOutputCP(1251);

    {
        pair<int, string> test1;
        test1.first = 1;
        test1.second = "TEST";
        cout << format("test1 {}\t{}", test1.first, test1.second) << endl;

        pair<int, string> test2{ 1, "TEST" };
        cout << format("test2 {}\t{}", test2.first, test2.second) << endl;

        cout << format("test1 = test2 {}", (test1 == test2)) << endl;
    }
    

    {
        typedef pair<int, string> ddata;
        
        ddata arr[]{ ddata(1,"A"), ddata(1,"A")};
        for (auto& a : arr) cout << format("{}\t{}", a.first, a.second) << endl;

        list<ddata> pattern;
        pattern.push_back(ddata(1, "A"));
        cout << endl;
    }


    {
        typedef set<short> lset;
        list<lset> items;
        items.push_back(lset{ 1 });
        items.push_back(lset{ 2 });
        items.push_back(lset{ 3 });        
        items.begin()->insert(2);

        list<lset>::iterator lit;
        lit = items.begin();
        advance(lit, 1);
        lit->insert(22);
        lit->insert(222);
        
        lit++;
        lit->insert(3000);

        for (auto& l : items) l.insert(144);

        for (auto& item : items) {
            for (auto& i : item) cout << i << '\t';
            cout << endl;
        }
        cout << endl;
    }

    {
        // MAP <key, value>

        map<int, string> myMap;
        myMap.insert(make_pair(1, "tel")); // добавить объект, через копирование(вначале создать, потом скопировать в map)
        myMap.insert(pair<int, string>(2, "noot")); // добавить объект, через копирование(вначале создать, потом скопировать в map)
        myMap.emplace(3, "monitor"); // добавить объект
        myMap.emplace(22, "keybord");

        
        for (auto i : { 22, 144 }) {
            auto find = myMap.find(i); // возвращяет итератор на найденную пару
            if (find != myMap.end()) cout << format("{} = {}\t{}", i, find->first, find->second) << endl;
            else cout << format("{} - not find", i) << endl;
        }

        //for (auto i : { 22, 144 })
        //    cout << myMap.at(i) << endl; // 144 - error
        
        cout << format("myMap[1] = {}", myMap[1]) << endl;
        myMap[1] = "TEL: IPhone"; // изменит по ключу хранимое значение
        cout << format("myMap[1] = {}", myMap[1]) << endl;

        myMap[4] = "TV"; // если ключа не существует, добавит новый элемент в контейнер
        cout << format("myMap[4] = {}", myMap[4]) << endl;

        //myMap.at(144); // вернет значение по ключу, если такого ключа не существует, вернет ошибку out_of_range
        //myMap.erase(122); // удалит по ключу, если существует.... инача ошибка

        cout << "\nmultimap" << endl;
        multimap<short, string> mmap;

        mmap.emplace(1, "A");
        mmap.emplace(2, "B");
        mmap.emplace(3, "C");
        for (auto& m : mmap) cout << format("({} - {})\t", m.first, m.second);
        cout << endl;
        
        mmap.emplace(3, "C");
        for (auto& m : mmap) cout << format("({} - {})\t", m.first, m.second);
        cout << endl;

        //mmap[3] = "CCC"; НЕ СУЩЕСТВУЕ ПЕРЕГРУЗКИ 

        



        
        // map<const unsigned short, const string> kv;
        map<const unsigned short, const string, bool> kv2;
        //map<const unsigned short, const string, bool, bool> kv3; // error
        map<const unsigned short, const string, int> kv4; // error

        typedef pair<short, pair<short, string>> kvd;
        map<short, kvd> kv5;
        //kv5.insert(make_pair(1, kvd( 1, "A" )));

        map<bool, short> kv6;
        kv6.emplace(true, 1);
        kv6.emplace(false, 1);
        kv6.emplace(false, 2);
        kv6.emplace(true, 2);
        for (auto& kv : kv6) cout << kv.first << '\t';
        cout << endl;

        multimap<bool, short> kv7;
        kv7.emplace(true, 1);
        kv7.emplace(false, 1);
        kv7.emplace(false, 2);
        kv7.emplace(true, 2);
        for (auto& kv : kv7) cout << kv.first << '\t';
        cout << endl;


    }
    


    return 0;
}


