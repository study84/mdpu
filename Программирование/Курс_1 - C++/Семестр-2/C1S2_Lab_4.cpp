#include <windows.h>
#include <iostream>
#include <string>
#include <format>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    
    cout << "Завдання 1: Задані дві матриці дійсних чисел A(N, M) і B(N, M).Обчислити матрицю C = A + B." << endl;
    
    size_t rows{}, columns{};

    cout << "Ведіть для матриці А і В кількість рядків(n) ";
    cin >> rows;

    cout << "Ведіть для матриці А і В кількість стовпців(m) ";
    cin >> columns;
    
    short** a = new short* [rows];
    short** b = new short* [rows];
    short** c = new short* [rows];
    string aa, bb, cc;    
    

    for (size_t row{}; row < rows; row++) {
        a[row] = new short[columns];
        b[row] = new short[columns];
        c[row] = new short[columns];
        aa = "";
        bb = "";
        cc = "";        
        for (size_t col{}; col < columns; col++) {
            a[row][col] = rand() % 21 - 10;
            b[row][col] = rand() % 21 - 10;
            c[row][col] = a[row][col] + b[row][col];
            aa += format("{:>5}\t", to_string(a[row][col]));
            bb += format("{:>5}\t", to_string(b[row][col]));
            cc += format("{:>5}\t", to_string(c[row][col]));
        }
        cout << format("{}\t{}\t{}", aa, bb, cc) << endl;        
    }

    cout << endl;
    
    
    cout << "Завдання 2: Написати програму множення двох матриць дійсних чисел B(N, M) і C(M, L)." << endl;

    /////////////////////////////////////////////////////////////////////////////
    //short A[][4]{ {2,-3,2}, {-6,10,8}, {-10,5,-9}, {7,3,-2} };
    //short B[][5]{ {-7,0,-10,-2,9}, {-6,-5,4,10,-8}, {-8,-9,10,0,-2} };

    //for (size_t r{}; r < rows; r++) {
    //    for (size_t c{}; c < columns; c++) cout << format("{:>5}\t", to_string(A[r][c]));
    //    cout << endl;
    //}
    //cout << endl;

    //for (size_t r{}; r < columns; r++) {
    //    for (size_t c{}; c < columns_l; c++) cout << format("{:>5}\t", to_string(B[r][c]));
    //    cout << endl;
    //}
    //cout << endl;
    //
    //

    //short** summ = new short* [4];

    //for (auto row{ 0 }; row < 4; row++) {
    //    summ[row] = new short[5];
    //    for (auto col{ 0 }; col < 5; col++) {
    //        summ[row][col] = 0;
    //        for (auto rc{ 0 }; rc < 3; rc++) {
    //            summ[row][col] += A[row][rc] * B[rc][col];
    //            //cout << format("{}\t{}\t{}\t{}\t{}\t{}", row, col, rc, A[row][rc], B[rc][col], summ[row][col]) << endl;
    //        }
    //    }

    //}    

    //for (auto r{ 0 }; r < 4; r++) {
    //    for (auto c{ 0 }; c < 5; c++)
    //        cout << summ[r][c] << ' ';
    //    cout << endl;
    //}    
    /////////////////////////////////////////////////////////////////////////////

    
    size_t columns_l{};
    cout << "Ведіть для матриці C кількість стовпців(l) ";
    cin >> columns_l;

    //cout << format("rows: {:>5}\tcolumns/rows: {:>5}\tcolumns_l: {:>5}", rows, columns, columns_l) << endl;

    for (size_t r{}; r < rows; r++) {
        for (size_t c{}; c < columns; c++) cout << format("{:>5}\t", to_string(b[r][c]));
        cout << endl;
    }
    cout << endl;    

    
    short** matrix = new short* [columns]; // rows        

    // наповнення матриці випадковими значеннями
    for (size_t r{}; r < columns; r++) {
        matrix[r] = new short[columns_l];        
        for (size_t cl{}; cl < columns_l; cl++) {
            matrix[r][cl] = rand() % 21 - 10;            
            cout << format("{:>5}\t", to_string(matrix[r][cl]));
        }
        cout << endl;
    }

    cout << endl;
    cout << "Матриця добуток:" << endl;


    short** mpon = new short* [rows];

    for (auto r{ 0 }; r < rows; r++) {
        mpon[r] = new short[columns_l];
        for (auto c{ 0 }; c < columns_l; c++) {
            mpon[r][c] = 0; // без обнулення не працює!!!
            for (auto rc{ 0 }; rc < columns; rc++) {
                mpon[r][c] += b[r][rc] * matrix[rc][c];
                //cout << format("{}\t{}\t{}\t{}\t{}\t{}", r, c, rc, b[r][rc], matrix[rc][c], mpon[r][c]) << endl;
            }
        }            
    }

    
    for (size_t r{}; r < rows; r++) {
        for (size_t c{}; c < columns_l; c++) cout << format("{:>5}\t", to_string(mpon[r][c]));
        cout << endl;
    }


    for (size_t r = 0; r < rows; r++) delete[] a[r], b[r], c[r];
    delete[] a, b, c;

    for (size_t r = 0; r < columns; r++) delete[] matrix[r];
    delete[] matrix;

    for (size_t r = 0; r < rows; r++) delete[] mpon[r];
    delete[] mpon;

}