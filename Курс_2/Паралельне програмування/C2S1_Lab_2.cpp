// 513-i Золотухін Андрій
// Напишіть програму, яка виконує перемноження двох квадратних матриць розміром NxN. 
// Вхідні дані : A, B - два цілих масиву розміром NxN.
// Вихідні дані : C – цілий масив NxN, що є результатом A * B

#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>



using namespace std;


//auto rnd = [](int max) {};

void print_martrix(const string name, const vector<vector<int>>& matrix);


int main()
{
    SetConsoleOutputCP(1251);    

    int ar{}, ac{}, br{}, bc{};

    do {
        printf_s("Введіть розмір матриці A(rows*columns) B(rows*columns): ");
        scanf_s("%d*%d %d*%d", &ar, &ac, &br, &bc);
        if (ac != br) printf_s("Кількість стовпчиків(колонок) матриці A має дорівнювати кількості рядків матриці B !!!\n");

    } while (ac != br);

    vector<vector<int>> A(ar, vector<int>(ac));
    vector<vector<int>> B(br, vector<int>(bc));
    vector<vector<int>> C(ar, vector<int>(bc));
            
    srand(time(NULL));
    for (size_t cr{ 0 }; cr < ac; cr++) {
        for (size_t r{ 0 }; r < ar; r++) A[r][cr] = 1 + rand() % 29;
        for (size_t c{ 0 }; c < bc; c++) B[cr][c] = 1 + rand() % 29;
    }
    
    print_martrix("A", A);
    print_martrix("B", B);

    for (size_t i{ 0 }; i < ac; i++)
        for (size_t r{ 0 }; r < ar; r++)
            for (size_t c{ 0 }; c < bc; c++)
                C[r][c] += A[r][i] * B[i][c];
    
    print_martrix("C", C);

    return 0;
}


void print_martrix(const string name, const vector<vector<int>>& matrix) {
    printf_s("Matrix %s\n", name.c_str());
    for (const auto& row : matrix) {
        for (int elem : row)
            printf_s("%d\t", elem);
        printf_s("\n");
    }
    printf_s("\n");
}



//printf_s("Matrix A\n");
    //for (size_t r{ 0 }; r < ar; r++) {
    //    for (size_t c{ 0 }; c < ac; c++)
    //        printf_s("%d\t", ma[r][c]);
    //    printf_s("\n");
    //}    
    //printf_s("\n");

    //printf_s("Matrix B\n");
    //for (size_t r{ 0 }; r < br; r++) {
    //    for (size_t c{ 0 }; c < bc; c++)
    //        printf_s("%d\t", mb[r][c]);
    //    printf_s("\n");
    //}
    //printf_s("\n");

    //printf_s("Matrix C\n");
    //for (size_t r{ 0 }; r < ar; r++) {
    //    for (size_t c{ 0 }; c < bc; c++)
    //        printf_s("%d\t", mc[r][c]);
    //    printf_s("\n");
    //}