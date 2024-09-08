// Динамический массив данных

#include <iostream>

using namespace std;

int main()
{
    int s{};
    cin >> s;
    
    int * arr = new int[s];
    
    for (short i{0}; i < s; i++) {
        cout << i + 1 << '\t';
        cin >> arr[i];
    }
    
    int sum{0};
    for (short i{0}; i < s; i++) sum += arr[i];
    
    cout << sum;

    return 0;
}
