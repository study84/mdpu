// Лекція 5. Масиви, рядки в С++Файл
// https://dfn.mdpu.org.ua/pluginfile.php/36267/mod_resource/content/1/Символьні%20масиви%20та%20рядки.pdf

#include <windows.h>
#include <iostream>
#include <ctime>


using namespace std;





int main() {
    SetConsoleOutputCP(1251);

	// символьні масиви та обробка рядків
    char vowels[5]{ 'a', 'e', 'i', 'o', 'u' };
    char vowels2[]{ 'a', 'e', 'i', 'o', 'u' };

    
    const unsigned short int s{10};
    char line[s]{};
    // cin.getline(char sink , streamsize size, char delimiter = '\n');
    std::cout << "введіть текст: ";
    cin.getline(line, s, '\n');
    for (unsigned short int i{0}; i < s; i++) std::cout << line[i] << '\t';
    std::cout << endl;

    // підрахунок кількості слів у реченні
    const unsigned short int size_text{256};
    char txt[size_text]{};
    std::cout << "введіть текст: ";
    cin.getline(txt, size_text, '\n');
    std::cout << endl;
    //
    //for (unsigned short int i{ 0 }; (i < size_text) and (txt[i] != '\0'); i++) std::cout << txt[i] << '\t';

    unsigned short int i{ 0 }, space{0};
    while (txt[i] != '\0') {        
        if (txt[i] == ' ') space++;
        i++;
    }
    std::cout << "words: " << '\t' << 1 + (space ? space : 0);


    return 0;
}