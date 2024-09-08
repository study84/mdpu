// количество вхождений значений в отсортированный массив

#include <iostream>
#include <string>

using namespace std;

int main()
{
    short arr[]{1,1,1,1,2,2,2,3,3,4,5,5,6};
    short size = sizeof(arr) / sizeof(arr[0]);
    short pattern{arr[0]};
    short start;
    short count{1};
    
    cout << size << endl;
    
    for(auto i{0}; i < size + 1; i++) {
        if(pattern == arr[i]) count++;
        else {
            cout << pattern << '\t' << start << '\t' << count << endl;
            pattern = arr[i];
            start = i;
            count = 1;
        }
    }
    
    
    
    

    return 0;
}