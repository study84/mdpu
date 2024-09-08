#include <iostream>

using namespace std;

int main()
{
    const int size{12};
    int arr[size] {1, 2, 3, 5, 7, 3, 2, 2, 3, 4, 5, 6};
    
    int best[]{-1, -1, -1};
    int f{0};
    
    for (int i{1}; i < size; i++) {
        cout << i << '\t' << arr[i - 1] << '\t' << arr[i] << '\t' << (arr[i - 1] <= arr[i]) << '\t' << f;
        if(arr[i - 1] <= arr[i])
            1;
        else {
            if(i - f > best[2]) {
                best[0] = f;
                best[1] = i;
                best[2] = i - f;
            }
            f = i;
            //cout << f;
        }
        
        //cout << i << '\t' << arr[i - 1] << '\t' << arr[i] << '\t' << (arr[i - 1] <= arr[i]) << endl;
        cout << endl;
    }
    
    cout << endl;
    cout << best[0] << '\t' << best[1] << '\t' << best[2] << endl;

    return 0;
}
