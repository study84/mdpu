// Лекція 5.2. Багатовимірні масиви
// https://dfn.mdpu.org.ua/mod/resource/view.php?id=166597

#include <windows.h>
#include <iostream>
#include <ctime>


using namespace std;




int main() {
    SetConsoleOutputCP(1251);

	// багатовимірні масиви
    
    // допускається заповнення не всіх значень
    double mass1[3][4]{
        {2.5f, 3.2f},
        {4.1},
        {2.8, 2.3, 0.9}
    };

    // встановлення значення за замовчуванням
    double mass2[][3]{
        {1.0},
        {1.0, 2.0},
        {1.0, 2.0, 3.0},
    };

    double mass3[][3][3]{
        { {1.0} },
        { {1.0, 2.0} },
        { {1.0, 2.0, 3.0} },
    };


    return 0;
}