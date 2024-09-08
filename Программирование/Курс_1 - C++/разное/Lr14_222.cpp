#include <iostream>

using namespace std;

int main()
{
    const int size{12};
    int arr[size] {1, 2, 3, 5, 7, 3, 2, 2, 3, 4, 5, 6};
    bool comparison[size];
    
    for (int i{0}; i < size - 1; i++) {
        comparison[i] = arr[i] <= arr[i + 1];
        cout << i << '\t' << arr[i] << '\t' << arr[i + 1] << '\t' << comparison[i] << endl;
    }
    
    cout << endl;
    
    int best[]{-1, -1, -1};
    int f{0}, e{0};
    for (int i{0}; i < size - 1; i++) {
        if (comparison[i]) {
            //continue;
            cout << i << '\t' << f << '\t' << i - f << endl;
            //e++;
        }
        else {
            cout << i << '\t' << f << '\t' << i - f << endl;
            if(best[2] < i - f) {
                best[0] = f;
                best[1] = i;
                best[2] = i - f;
            }
            f = i;
            //e = 0;
        }
    }
    cout << endl;
    cout << best[0] << '\t' << best[1] << '\t' << best[2] << endl;

    return 0;
}
