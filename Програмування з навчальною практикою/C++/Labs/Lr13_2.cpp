#include <windows.h> 
#include <iostream>
#include <format>

using namespace std;

int main()

{
    SetConsoleOutputCP(1251);

    const int size = 24; // довжина рядка    
    char txt[size];
    //char txt[]{ " dsd kfkdf k dfc kK   " };    
    
    int count{0}; // ознака виявлення символу
    char letter[size];
    int letter_count[size];
    int letter_i{0};
    bool add_new_letter{};
    bool space{ false };

    cout << "вводите речення ";
    cin.getline(txt, size, '\n');    

    for (int t{ 0 }; t < size; t++) {
        if (txt[t] == ' ') space = true;        
        if (txt[t] >= 'A' and txt[t] <= 'Z' or txt[t] >= 'a' and txt[t] <= 'z') {
            // 9. Дано масив символів, що містить текст. Підрахувати кількість букв k в останньому слові масиву
            if (space) {
                count = 0;
                space = false;
            }
            if (txt[t] == 'K' or txt[t] == 'k') count++;
            // 10. Дано масив символів. Підрахувати, скільки різних символів у ньому. Вивести їх на екран. (з додатковими умовами)
            add_new_letter = true;
            for (int l{ 0 }; l < letter_i; l++) {                
                if (txt[t] == letter[l]) {                    
                    letter_count[l] += 1;
                    add_new_letter = false;                    
                }
            }
            if (add_new_letter) {                
                letter[letter_i] = txt[t];
                letter_count[letter_i] = 1;
                letter_i++;                
            }
        }        
    }

    cout << "9. Дано масив символів, що містить текст. Підрахувати кількість букв k в останньому слові масиву" << endl;
    cout << "літер K / k в останньому слові " << count << endl;

    cout << endl;
    cout << "10. Дано масив символів. Підрахувати, скільки різних символів у ньому. Вивести їх на екран. (з додатковими умовами)";
    
    /*for (int i{ 0 }; i < letter_i; i++)
        cout << letter[i] << '\t' << letter_count[i] << endl;*/

    // сортування за зменшенням частоти зустрічальності літери
    cout << endl;
    for (int i1{ 0 }; i1 < letter_i; i1++)
        for (int i2{ i1 + 1 }; i2 < letter_i; i2++)
            if (letter_count[i1] < letter_count[i2]) {
                swap(letter_count[i1], letter_count[i2]);
                swap(letter[i1], letter[i2]);
            }
    // сортування за зменшенням літери
    for (int i1{ 0 }; i1 < letter_i; i1++)
        for (int i2{ i1 + 1 }; i2 < letter_i; i2++) 
            if (letter_count[i1] == letter_count[i2] and letter[i1] > letter[i2])
                swap(letter[i1], letter[i2]);
    
    for (int i{ 0 }; i < letter_i; i++)
        cout << format("{}={}", letter[i], letter_count[i]) << '\t';

    return 0;
}
