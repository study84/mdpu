// 823-і Золотухін Андрій Олександрович
// ЛАБОРАТОРНА  РОБОТА №18
#include <iostream>
#include <vector>
#include <chrono> 

#include "Sort.h"

using namespace std;


//struct arr {
//    string name;
//    struct { double time; vector<int>* arr; } a50;
//    struct { double time; vector<int>* arr; } a500;
//    struct { double time; vector<int>* arr; } a5k;
//    struct { double time; vector<int>* arr; } a500k;
//
//    arr() {
//        a50.arr = new vector<int>(50);
//        a500.arr = new vector<int>(500);
//        a5k.arr = new vector<int>(5000);
//        a500k.arr = new vector<int>(500000);
//    }
//
//    ~arr() {
//        delete a50.arr;
//        delete a500.arr;
//        delete a5k.arr;
//        delete a500k.arr;
//    }
//};


vector<int>* gen(const unsigned int count, const int min, const int max) {
    vector<int>* genSet = new vector<int>;
    for (auto i{ 0 }; i < count; i++) genSet->push_back(min + rand() % (max - min + 1));
    return genSet;
}


int measureSortTime(void (*sortFunc)(vector<int>&), vector<int>& data) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(data);
    auto stop = chrono::high_resolution_clock::now();
    auto  duration = chrono::duration_cast<chrono::microseconds>(stop - start);    
    return duration.count();
}


int measureSortTime(void (*sortFunc)(vector<int>&, int, int), vector<int>& data, int num1, int num2) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(data, num1, num2);
    auto stop = chrono::high_resolution_clock::now();
    auto  duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    return duration.count();
}


//void test(const string type_name, const int min, const int max, const int counts[], void (*sortFunc)(vector<int>&)) {
//    cout << format("{:<16}\t", type_name);
//    vector<int>* data;
//    const int size = sizeof(counts[0]) / sizeof(counts);
//    for (auto c : counts) {
//        data = gen(c, min, max);
//        cout << format("{:>8}\t", measureSortTime(sortFunc, *data));
//    }
//    cout << endl;
//    delete data;
//}




int main()
{
    srand(time(nullptr));

    //string names[]{ "Bubble Sort", "Insertion Sort", "Selection Sort", "Quick Sort", "Merge Sort", "Counting Sort", "Radix Sort" };
    //vector<arr> arrs(7);
    //auto time_start = chrono::high_resolution_clock::now();
    //for (auto i{ 0 }; i < arrs.size(); i++) {
    //    arrs[i].name = names[i];
    //    *(arrs[i].a50.arr) = *gen(arrs[i].a50.arr->size(), 1, arrs[i].a50.arr->size() * 3);
    //    *(arrs[i].a500.arr) = *gen(arrs[i].a500.arr->size(), 1, arrs[i].a500.arr->size() * 3);
    //    *(arrs[i].a5k.arr) = *gen(arrs[i].a5k.arr->size(), 1, arrs[i].a5k.arr->size() * 3);
    //    *(arrs[i].a500k.arr) = *gen(arrs[i].a500k.arr->size(), 1, arrs[i].a500k.arr->size() * 3);
    //}
    //auto time_stop = chrono::high_resolution_clock::now();
    //auto time_duration = chrono::duration_cast<std::chrono::microseconds>(time_stop - time_stop);
    ////cout << "Create Time: " << time_duration.count() << endl;
    ////for (auto i{0}; i < 50; i++) cout << (*(arrs[0]).a50.arr)[i] << '\t';
    ////vector<int> data = *(arrs[0]).a50.arr;
    
    const int min{ 1 }, max{ 1000000 }, counts[]{ 50, 500, 5000, 500000 };
    cout << format("{:<16}\t{:^8}\t{:^8}\t{:^8}\t{:^8}", "Type sort", "50", "500", "5000", "500000") << endl;    
    vector<int>* data;

    //cout << format("{:<16}\t", "Bubble Sort");
    //for (auto c : counts) {        
    //    data = gen(c, min, max);
    //    //cout << c << endl;
    //    cout << format("{:>8}\t", measureSortTime(bubbleSort, *data));
    //}
    //cout << endl;    

    //cout << format("{:<16}\t", "Insertion Sort");
    //for (auto c : counts) {        
    //    data = gen(c, min, max);
    //    cout << format("{:>8}\t", measureSortTime(insertionSort, *data));
    //}
    //cout << endl;

    //cout << format("{:<16}\t", "Selection Sort");
    //for (auto c : counts) {
    //    data = gen(c, min, max);
    //    cout << format("{:>8}\t", measureSortTime(selectionSort, *data));
    //}
    //cout << endl;

    cout << format("{:<16}\t", "Quick Sort");
    for (auto c : counts) {
        data = gen(c, min, max);
        cout << format("{:>8}\t", measureSortTime(quickSort, *data, 0, data->size() - 1));
    }
    cout << endl;

    cout << format("{:<16}\t", "Merge Sort");
    for (auto c : counts) {
        data = gen(c, min, max);
        cout << format("{:>8}\t", measureSortTime(mergeSort, *data, 0, data->size() - 1));
    }
    cout << endl;

    cout << format("{:<16}\t", "Counting Sort");
    for (auto c : counts) {
        data = gen(c, min, max);
        cout << format("{:>8}\t", measureSortTime(countingSort, *data));
    }
    cout << endl;
    
    cout << format("{:<16}\t", "Radix Sort");
    for (auto c : counts) {
        data = gen(c, min, max);
        cout << format("{:>8}\t", measureSortTime(radixSort, *data));
    }
    cout << endl;


    return 0;
}
