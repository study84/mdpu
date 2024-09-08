#include <windows.h>
#include <iostream>
#include <format>
#include <string>

#include <map>
#include <algorithm>

#include <utility> // for std::pair


using namespace std;



int main()
{
    SetConsoleOutputCP(1251);

    short arr[]{ 1,2,3,4,5,6,1,2,3,4,1,2,3,2 };

    map<string, short> arri;
    
    auto it1 = begin(arr);
    auto it2 = end(arr);
    

    arri["count 1"] = count(it1, it2, 1); // сколько 1 в массиве
    arri["count 2"] = count(it1, it2, 2); // сколько 1 в массиве


    //arri["find 2"] = find(it1, it2, 2); // !!!, вернет ссылку& на первый наденный элемент   
    auto& aa = *(find(it1, it2, 2));
    aa += 10;
    cout << "aa " << aa << endl;
    arri["find 4(indx)"] = find(it1, it2, 4) - it1; // вернет индекс первого значения
    
    arri["find 144(indx)"] = find(it1, it2, 144) == it2; // если элемента не существует в массиве, вернет it2 = end = 14 индекс (всего 0-13)


    arri["min_element(indx)"] = min_element(it1, it2) - it1;
    arri["max_element(indx)"] = max_element(it1, it2) - it1;
    cout << format("min/max {} / {}", *min_element(it1, it2), *max_element(it1, it2)) << endl;

    arri["binary_search (144)"] = binary_search(it1, it2, 144); // true / false

    arri["lower_bound (1)"] = lower_bound(it1, it2, 1) - it1; // вернет индекс первого значения искомого элемента
    arri["upper_bound (1)"] = upper_bound(it1, it2, 1) - it1; // вернет индекс первого после значения искомого элемента

    sort(it1, it2); // сортировка по итераторам начальной позиции и последней позиции
    //stable_sort(it1, it2); // ????
    
    replace(it1, it2, 1, 10); // заменить согласно итераторам все найденные x на y

    reverse(it1, it2); // развернуть контейнер

    
    
    
    for (auto& a : arri) cout << format("{} = {}", a.first, a.second) << endl;
    
    
    for (auto& a : arr)  cout << a << '\t';
    cout << endl;


    short arr1[]{ 3,5,6,7,3,2,1 };
    short arr2[]{ 36,87,90,54,323,2,1 };
    short* arr3;
    
    //merge(arr1, arr1 + 5, arr2, arr2 + 3, arr3);
    
    map<string, short*> iter;
    iter["arr1b"] = begin(arr1);
    iter["arr1e"] = end(arr1);
    iter["arr2b"] = begin(arr2);
    iter["arr2e"] = end(arr2);    
    
    //merge(iter["arr1b"], iter["arr1e"], iter["arr2b"], iter["arr2e"], arr3);

    //for (auto a{ begin(arr3) }; ) cout << *a << '\t';
    //begin(arr3);
    //delete[] arr3;
    cout << endl;

    sort(arr1, end(arr1));
    for (auto a : arr1) cout << a << '\t';
    cout << endl;

    short* arr1u = unique(arr1, end(arr1));
    //for (auto a: arr1u) cout << a << '\t';
    //delete[] arr1u;
    cout << endl;

    //random_shuffle(iter["arr1b"], iter["arr1e"]);

    

    do {
        for (int a : arr1)  cout << a << ' ';
        cout << endl;
    } while (next_permutation(iter["arr1b"], iter["arr1e"])); // генерирует следующую(все) возможные перестановки массива данных


    do {
        for (int a : arr1)  cout << a << ' ';
        cout << endl;
    } while (prev_permutation(iter["arr1b"], iter["arr1e"])); // генерирует предыдущую(все) возможные перестановки массива данных

    return 0;
}


