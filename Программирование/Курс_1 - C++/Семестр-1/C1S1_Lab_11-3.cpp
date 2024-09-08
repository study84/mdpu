#include <windows.h> 
#include <iostream>
#include <format>

using namespace std;

int main()

{
    SetConsoleOutputCP(1251);    
    
    double arr[4][4]{
        {2.3, -5, 6.2, 12},
        {10.3, 0.23, 32.6, 8.33},
        {-7.1, 4, -0.25, 9},
        {-1, -7.7, 8, 1.98}
    };   

    int s1{}, s2{}, max_x{ 0 }, max_y{0};
    double max{ arr[0][0] };
    double sum1{ 0 }, multiplication1{ 1 }, sum2{ 0 }, multiplication2{ 1 };
    double diagonal1_sum{ 0 }, diagonal1_m{ 1 }, diagonal2_sum{ 0 }, diagonal2_m{ 1 };

    for (int i{ 0 }; i < 4; i++) {
        for (int i1{ 0 }; i1 < 4; i1++)
            cout << arr[i][i1] << '\t';
        cout << endl;
    }

    do {
        cout << "суму та добуток якого рядка ви хочете знайти? ";
        cin >> s1;
        if (0 < s1 and s1 < 5) break;
        else cout << "такого рядка не існує!" << endl;    
    } while (1);

    do {
        cout << "суму та добуток якого стовпця ви хочете знайти? ";
        cin >> s2;
        if (0 < s2 and s2 < 5) break;
        else cout << "такого стовпця не існує!" << endl;
    } while (1);

    for (int i{ 0 }, d2{3}; i < 4; i++, d2--) {
        for (int i1{ 0 }; i1 < 4; i1++) {
            if (arr[i][i1] > max) { // Елемент із максимальним значенням
                max = arr[i][i1];
                max_x = i;
                max_y = i1;
            }
            if (i == s1) { // елементів рядка
                sum1 += arr[i][i1];
                multiplication1 *= arr[i][i1];
            }
            if (i == i1) { // елементів головної діагоналей
                diagonal1_sum += arr[i][i1];
                diagonal1_m *= arr[i][i1];
            }
            if (d2 == i1) {// елементів побічної діагоналей
                diagonal2_sum += arr[i][i1];
                diagonal2_m *= arr[i][i1];
            }            
        }
        if (i == s2) { // елементів стовпця
            // оскільки елементів не багато простіше прописати вручну
            sum2 += arr[0][i] + arr[1][i] + arr[2][i] + arr[3][i];
            multiplication2 *= arr[0][i] * arr[1][i] * arr[2][i] * arr[3][i];
        }            
    }
    cout << format("1) Елемент із максимальним значенням {}, рядок={} стовпець={}", max, max_x, max_y) << endl;
    cout << format("2) Обчислити суму={:4.3f} і добуток={:4.3f} елементів рядка {}", sum1, multiplication1, s1) << endl;
    cout << format("3) Обчислити суму={:4.3f} і добуток={:4.3f} елементів стовпця {}", sum2, multiplication2, s2) << endl;
    cout << format("4.1) Обчислити суму={:4.3f} і добуток={:4.3f} елементів головної діагоналей", diagonal1_sum, diagonal1_m) << endl;
    cout << format("4.2) Обчислити суму={:4.3f} і добуток={:4.3f} елементів побічної діагоналей", diagonal2_sum, diagonal2_m) << endl;    
    return 0;
}

