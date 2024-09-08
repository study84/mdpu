// ЛАБОРАТОРНА  РОБОТА №17
// варіант 8

#include <windows.h>
#include <iostream>
#include <format>
#include <string>

#include <set>
#include <list>



using namespace std;


template<typename dset>
set<dset>* gen(const short count, const dset min, const dset max);


template<typename dset>
void print(const set<dset>& dataset);


template<typename dset>
set<dset>* intersections(const set<dset>& first, const set<dset>& second);


template<typename dset>
bool subset(const set<dset>& first, const set<dset>& second);




int main()
{
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    //set<int>* nums = gen(5, 1, 10);
    //set<char>* abc = gen(5, 'a', 'z');
    //delete nums, abc;
    
    cout << "Завдання 1: Перетин множин : знайдіть спільні елементи двох множин" << endl;
    set<int>* nums1 = gen(10, 1, 35); // not short !!!
    set<int>* nums2 = gen(10, 15, 50); // not short !!!
    set<int>* result1 = intersections(*nums1, *nums2);
    delete nums1, nums2, result1;
    cout << endl;
    set<char>* abc1 = gen(10, 'a', 'v');
    set<char>* abc2 = gen(10, 'f', 'z');
    set<char>* result2 = intersections(*abc1, *abc2);
    delete abc1, abc2, result2;
    cout << endl;

    
    cout << "Завдання 2. Перевірка підмножини : напишіть функцію, яка перевіряє, чи є одна множина під - множиною іншої." << endl;
    set<int> dataset{ 1,2,3,4,5,6,7,8,9,0 };
    set<int> datasubset{2,3,4,5,7,11};
    cout << "SubSet " << subset(dataset, datasubset) << endl;
    cout << endl;

    
    cout << "Завдання 3. Список множин: реалізуйте список, де кожен елемент є множиною, і виконайте операції об'єднання та перетину всіх множин у списку." << endl;    
    list<set<int>*> ListSets;
    for (auto i{ 0 }; i < 5; i++) ListSets.push_back(gen(20, 1, 100));

    //for (const auto& i : ListSets) cout << &(*i) << endl; // адреси set в list

    //for (const auto& list : ListSets)
    //    for (const auto& l : *list)            
    //        total.insert(l);
        
    
    set<int> total;
    set<int> tmp;
    for (auto iterA = ListSets.begin(), iterB = ListSets.begin(); iterA != ListSets.end(); iterA++) {
        // об'єднання
        //auto setA = *iterA;
        //for (auto& s : *set) cout << s << '\t';
        //cout << endl;
        //for (const auto& s : *setA) total.insert(s);
        for (const auto& s : *(*iterA)) total.insert(s);
        
        
        // перетини
        /*auto setB = *(++iterB);
        cout << ">>>>" << endl;
        print(*setA);
        print(*setB);
        intersections(*setA, *setB);*/        
        
        /*auto iterTemp = iterB;
        cout << "*iterB=" << *iterB << '\t' << "*iterTemp=" << *iterTemp << endl;
        iterB++;
        cout << "*iterB=" << *iterB << '\t' << "*iterTemp=" << *iterTemp << endl;
        iterTemp++;
        cout << "*iterB=" << *iterB << '\t' << "*iterTemp=" << *iterTemp << endl;*/
        
        //iterB++;
        for (auto iterTemp = ++iterB; iterTemp != ListSets.end(); iterTemp++) {
            //if (!tmp.empty()) tmp.clear();
            //auto setB = *(++iterTemp);
            //intersections(*setA, *setB);
            //print(*iterTemp);
            //cout << "*iterA=" << *iterA << '\t' << "*iterB=" << *iterB << '\t' << "*iterTemp=" << *iterTemp << endl;
            intersections(*(*iterA), *(*iterTemp));
        }        
    }
    //delete tmp;

    cout << format("загальні значення({}):", total.size()) << endl;
    print(total);

    return 0;
}


template<typename dset>
set<dset>* gen(const short count, const dset min, const dset max) {
    set<dset>* genSet = new set<dset>;
    for (auto i{ 0 }; i < count; i++) genSet->insert(min + rand() % (max - min + 1)); // '->' используется в C++ для доступа к членам объекта через указатель на объект или указатель на экземпляр класса
    print(*genSet);
    return genSet;
}


template<typename dset>
void print(const set<dset>& dataset) {
    //for (auto i: dataset) cout << i << '\t';
    //for (auto i = begin(dataset); i != end(dataset); ++i) cout << i << '\t';
    //for (auto it = dataset->begin(); it != dataset->end(); ++it) cout << *it << '\t';
    for (const auto i : dataset) cout << i << '\t';
    cout << endl;
}


template<typename dset>
set<dset>* intersections(const set<dset>& first, const set<dset>& second) {
    set<dset>* overall_values = new set<dset>;
    
    //if (first->size() > second->size()) {
    //    for (auto it = second->begin(); it != second->end(); ++it) {
    //        if (first->find(*it) != first->end()) overall_values->insert(*it); // cout << *it << endl;
    //    }
    //}
    //else {
    //    for (auto it = first->begin(); it != first->end(); ++it) {
    //        if (second->find(*it) != second->end()) overall_values->insert(*it); // cout << *it << endl;
    //    }
    //}

    if (first.size() > second.size()) {
        for (const auto& i : second) if (first.find(i) != first.end()) overall_values->insert(i);
    }
    else {
        for (const auto& i: first) if (second.find(i) != second.end()) overall_values->insert(i);
    }

    print(*overall_values);

    return overall_values;
}


template<typename dset>
bool subset(const set<dset>& first, const set<dset>& second) {
    if (first.size() > second.size()) {        
        for (const auto& i : second) if (first.find(i) == first.end()) return false;
    }
    else {        
        for (const auto& i : first) if (second.find(i) == second.end()) return false;
    }
    return true;
}