#include <windows.h>
#include <iostream>
#include <fstream> // библиотека для работы с файлами
#include <string>
#include <format>

using namespace std;

string folder{"C:\\Users\\Admin\\Desktop\\files_cpp\\"};


void save_f(string file);
void read_f(string file);


int main()
{
    SetConsoleOutputCP(1251);
    /*
    Stream(Потоки) - специальный тип данных для работы с файлами
    ifstream - режим чтения 
    ofstream - режим записи
    fstream - чтения / записи
    */
    
    ofstream FileWriter;

    /*
    Режимы открытия файлов
    ios::in режим чтения, по умолчанияю для ifstream
    ios::out режим записи(с перезаписью), по умолчанию для ofstream
    ios::app - режим записи в конец файла
    ios::ate - перейти в конец уже открытого файла
    ios::trunc - очистить файл
    ios::nocreate - не открывать файл, если он НЕ СУЩЕСТВУЕТ
    ios::noreplace - не открывать существующий файл
    */

    FileWriter.open(folder + "test_cpp.txt");
    FileWriter << "ТЕСТ ЗАПИСИ-1" << endl;
    FileWriter << "ТЕСТ ЗАПИСИ-2";
    FileWriter << endl;
    FileWriter << "Write1\t" << "Write2";

    FileWriter.close(); // ЗАКРЫВАТЬ ОБЯЗАТЕЛЬНО !!!

    //------------------------------------------------------------------------
    
    //ofstream File1(folder + "test2_cpp.txt");
    ofstream FileWriter1{ folder + "test2_cpp.txt" };

    string txt;
    for (auto i{ 0 }; i < 3; i++) {
        cin >> txt;
        FileWriter1 << format("{}\t{}", i, txt) << endl;
    }        

    FileWriter1.close();

    //------------------------------------------------------------------------

    ifstream FileRead;

    FileRead.open(folder + "test_cpp.txt");

    if (FileRead) {
        string fileread;

        // Чтение до разделитиля: пробел, конец строки
        /*while (!FileRead.eof()) {
            FileRead >> fileread;
            cout << fileread << endl;
        }*/

        // Чтение построчно
        while (!FileRead.eof()) {
            getline(FileRead, fileread);
            cout << fileread << endl;
        }

        FileRead.close();
    }


    // Обробка двійкових файлів
    // ПРИ ЗАПИСІ ІНФОРМАЦІЇ У ДВІЙКОВИЙ ФАЙЛ СИМВОЛИ ТА ЧИСЛА ЗАПИСУЮТЬСЯ У ВИГЛЯДІ ПОСЛІДОВНОСТІ БАЙТ.
    //------------------------------------------------------------------------
    
    // За допомогою бібліотеки <fstream>
    string f = format("{}test_bin_cpp.bin", folder);    
    save_f(f);
    read_f(f);

    // За допомогою бібліотеки <iostream>


    

    return 0;
}




void save_f(string file)
{
    ofstream Bfile(file, ios::binary);
    if (Bfile.is_open()) {
        char data[] = { 'H', 'e', 'l', 'l', 'o' };
        Bfile.write(data, 5);
        Bfile.close();        
    }    
}


void read_f(string file)
{
    ifstream Bfile(file, ios::binary | ios::ate);
    if (Bfile.is_open()) {
        streamsize size = Bfile.tellg();
        Bfile.seekg(0, ios::beg);
        char* buffer = new char(size);
        if (Bfile.read(buffer, size)) std::cout << buffer;
        Bfile.close();
    }
    
}