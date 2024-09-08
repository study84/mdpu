#include <iostream>
#include <string>

using namespace std;


struct DATA {
    string name;
    int count;
    
    void print() {
        cout << name << '\t';
    }
};


DATA* func(const unsigned short size = 6) {
    string az{"abcdef"};
    
    DATA* arr = new DATA[size];
    
    for(auto a {0}; a < size; a++) {
        arr[a].name = az[a] + to_string(a * 10);
        arr[a].count = (a * 10);
    }
    
    return arr;
}


int main()
{
    DATA test;
    test.name = "AAA";
    test.count = 111;
    
    
    DATA arr[] = {
        {"AAA", 1}, {"Bbb", 22}, {"C", 333}
    };
    
    for(auto a: arr) cout << a.name << '\t';
    cout << endl;
    for(auto a: arr) a.print();
    
    cout << endl;
    
    unsigned short size;
    cin >> size;
    DATA* arr2 = func(size);
    for(auto a {0}; a < size; a++) cout << arr2[a].name << '\t';
    
    //delete[] arr, arr2;
    

    return 0;
}
