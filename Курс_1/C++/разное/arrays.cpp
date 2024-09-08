#include <iostream>
using namespace std;

double yield(double array[][4], int n);
double yield(double array, int n, int m);

int main() 
{
    double beans[3][4] = { { 1.0,  2.0,  3.0,  4.0 },
                             { 5.0,  6.0,  7.0,  8.0 },
                             { 9.0, 10.0, 11.0, 12.0 } };

    double beans1=new double*[3];
    double k = 1.0;
    for (int i{}; i < 3; i++)
    {
        beans1[i] = new double[4] ;
        for (int j{}; j < 4; j++)
        {
            beans1[i][j] = k;
            k++;
        }
    }



    cout << endl << "Yield = " << yield(beans, sizeof beans / sizeof beans[0])
        << endl;
    cout << endl << "Yield = " << yield(beans1, 3, 4);
}

double yield(double beans[][4], int count)
{
    double sum(0.0);
    for (int i = 0; i < count; i++) // Цикл рядків
        for (int j = 0; j < 4; j++) // Цикл за елементами рядка row
            sum += beans[i][j];
    return sum;

}

double yield(double** beans, int n, int m)
{
    double sum(0.0);
    for (int i = 0; i < n; i++) // Цикл рядків
        for (int j = 0; j < m; j++) // Цикл за елементами рядка row
            sum += beans[i][j];
    return sum;
}
