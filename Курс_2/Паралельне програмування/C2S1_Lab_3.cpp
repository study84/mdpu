// 513-i Золотухін Андрій

// 513-i Золотухін Андрій

#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <vector>


using namespace std;


int main()
{
    SetConsoleOutputCP(1251);    

    printf_s("Завдання 2: Напишіть програму, в якій утворюються 4 нитки і кожна нитка виводить на екран рядок \"Hello World!\".\n");
    omp_set_num_threads(4);
#pragma omp parallel
    {        
        printf_s("%d: Hello, World!\n", omp_get_thread_num());
    }

    printf_s("Завдання 3: Напишіть програму, в якій створюється 4 нитки, і кожна нитка виводить на екран свій номер та загальну кількість ниток.\n");
#pragma omp parallel
    {
        printf_s("I am %d thread from %d threads!\n", omp_get_thread_num(), omp_get_num_threads());
    }
// ************************************************************************************************************************************************

    printf_s("Завдання 4: Розробте програму, щоб знайти мінімальне (максимальне) значення серед елементів вектора.\n");
    
    int vsize{}, threads{};
    do {
        printf_s("Введіть розмір V(вектора) і T(число ниток) -> V T: ");
        scanf_s("%d %d", &vsize, &threads);
        if (vsize < threads) printf_s("розмір вектора (V) >= числа ниток (T) !!!\n");
    } while (vsize < threads);
    
    omp_set_num_threads(threads);
    
    vector<int> arr(vsize);
    // Генератор даних вектора
    srand(time(NULL));
#pragma omp parallel
    {
        int start{}, stop{}, thread{ omp_get_thread_num() };
        start = thread * (vsize / threads);
        stop = (thread == threads - 1) ? vsize : start + vsize / threads;
        for (int i{ start }; i < stop; i++) arr[i] = rand(); // (rand() % (100000000 - 1 + 1) + 1);
        //printf_s("%-4d start: %-6d stop: %-6d\n", thread, start, stop);
    }
    //for (int i{ 0 }; i < arr.size(); i++) printf_s("%d: %d\n", i, arr[i]);
    // пошук minmax вектора в розрізі ниток
    int gmin{ arr[0] }, gmax{ arr[0] };
#pragma omp parallel // shared(gmin, gmax) //prived(lmin, lmax)
    {
        int start{}, stop{}, thread{ omp_get_thread_num() }, lmin{}, lmax{};
        start = thread * (vsize / threads);
        stop = (thread == threads - 1) ? vsize : start + vsize / threads;
        lmin = arr[start];
        lmax = arr[start];
        for (int i{ start + 1 }; i < stop; i++) {
            lmin = min(lmin, arr[i]);
            lmax = max(lmax, arr[i]);
        }
        printf_s("%-4d start: %-6d stop: %-6d min: %-8d max: %-8d\n", thread, start, stop, lmin, lmax);
        gmin = min(gmin, lmin);
        gmax = max(gmax, lmax);
    }
    // підсумок пошуку
    printf_s("MIN: %d\tMAX: %d\n\n", gmin, gmax);
 // ************************************************************************************************************************************************


    printf_s("Завдання 5: Дано одновимірний масив A з n елементів, розташований у локальній пам'яті.\
        Елементи масиву A задаються у циклі за такою формулою a(i)=i*m, де m – статична змінна. Змінна m задається головною ниткою. Написати програму завдання масиву A, а також визначення часу роботи циклу.\
        Програми виводить на екран (файл) час виконання циклу. (Примітка: використання опцій shared, private, threadprivate, copyin parallel директиви).\n");
    //https://dfn.mdpu.org.ua/pluginfile.php/1590/mod_resource/content/2/Лабораторная%20работа%203_.pdf
    int n, m;
    printf_s("Укажіть розмір (A)масиву та (M)константу (A M): ");
    scanf_s("%d %d", &n, &m);
    int* a = new int[n];
    double start_time = omp_get_wtime();    
#pragma omp parallel shared(n,m, a) //private(a)
    {
        printf_s("I am %d thread from %d threads!\n", omp_get_thread_num(), omp_get_num_threads());
        for (int i{ 0 }; i < n; i++) a[i] = i * m;
    }
    double end_time = omp_get_wtime();
    printf_s("Time: %f\n\n", end_time - start_time);
    delete[] a;
    
    
    return 0;
}

/*
    int vsize{10}, threads{5}, t{}, start{}, stop{}; // threads
    cout << vsize / threads << '\t' << vsize % threads << endl;
    t = vsize / threads;


    for (int i{0}; i < threads; i++){
        start = i * t;
        stop = (i == threads - 1) ? vsize : start + t;
        cout << i << '\t' << "start: " << start << '\t' << "stop: " << stop << endl;
    }
*/

