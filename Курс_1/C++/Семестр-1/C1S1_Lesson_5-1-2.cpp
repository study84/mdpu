// Лекція 4. Цикли в С++Файл
// https://dfn.mdpu.org.ua/pluginfile.php/36266/mod_resource/content/1/Цикли%20у%20мові%20c%2B%2B%20лек%204.pdf

#include <windows.h>
#include <iostream>
#include <ctime>

using namespace std;





int main() {
	SetConsoleOutputCP(1251);

	// СОРТУВАННЯ МАСИВІВ
    // _________________________


    // сортування бульбашкою
    int e{}, mass[]{ 11,9,7,5,3, -1, };
    for (int s1{}; s1 < 6; s1++)
        for (int s2{}; s2 < 6; s2++)
            if (mass[s1] < mass[s2]) {
                e = mass[s1];
                mass[s1] = mass[s2];
                mass[s2] = e;
                // swap(mass[s1], mass[s2]);
            }

    for (int s1{}; s1 < 6; s1++) cout << mass[s1] << '\t';
    cout << endl;

    //mass[]{11,9,7,5,3, -1,};
        
    //// НЕ работает!!!
    //int mass2[]{ 11,9,7,5,3, -1, }, i{0};
    //bool flag{ false };
    //do {
    //    for(int j = 6 - 2; j >= i; j--)
    //        if (mass2[j] > mass2[j + 1]) {
    //            swap(mass2[j], mass2[j + 1]);
    //            flag = true;
    //        }
    //    i++;
    //} while (flag);

    //for (int s1{}; s1 < 6; s1++) cout << mass2[s1] << '\t';
    //cout << endl;


    //сортування вибору
    // ???????
    

    // пошук від'ємних значень і копіювання цих значень у новий масив
    const int N = 5;
    int a1[N], b1[N], count{0};
    srand(time(NULL));
    // формування масиву випадковими значеннями
    for (int i{ 0 }; i < N; i++) {
        a1[i] = rand() % (10 - (-10)) + (-10);
        cout << i << " \t" << a1[i] << endl;
    }
    // перевірка на відповідність умовам і копіювання значень у новий масив
    for (int i{ 0 }; i < N; i++)
        if (a1[i] < 0) {
            b1[count] = a1[i];
            count++;
        }
    // виведення шуканих значень із другого масиву
    for (int i{ 0 }; i < count; i++) cout << b1[i] << '\t';


    // знайти в масиві елементи, що дорівнюють X або встановити що такі елементи відсутні
    int find{ -1 }, element{-1};
    // * використовуємо попередні масиви
    for (int i{ 0 }; i < N; i++)
        if (a1[i] == find) {
            element = i;
            //cout << "елемент " << i << " відповідає умові пошуку" << endl;
            break;
        }
    if (element > -1)
        cout << "першим був знайдений елемент " << element << " який відповідає умовам пошуку";
    else cout << "елементів, що відповідають умовам пошуку, не знайдено" << endl;
	
	return 0;
}