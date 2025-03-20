// 513-і, Золотухін Андрій
// Навчальна практика (технологічна) ОП Професійна освіта. Комп’ютерні технології 2 курс
// Завдання 1 - Tiles.cpp
//

#include <iostream>
#include <string>
#include <format>
#include <cmath>

using namespace std;

typedef unsigned short ushort;

class Tiles {
    public:
        string brend;
        string color;
    private:
        ushort width; // ширину
        ushort height; // висоту
        float price;

    public:
        Tiles() {
            brend = "No Name";
            color = "Grey";
            width = 20;
            height = 20;
            price = 15;
        }

        Tiles(string brend, string color, ushort width, ushort height, float price = 15) {
            this->brend;
            this->color;
            this->width;
            this->height;
            this->price;        
        }


        bool set_width(ushort _width) {            
            return this->width = _width;
        }

        ushort get_width() {            
            return this->width;
        }
        //
        bool set_height(ushort _height) {            
            return this->height = _height;
        }

        ushort get_height() {
            return this->height;
        }
        //
        bool set_price(float _price) {            
            return this->price = _price;
        }

        float get_price() {             
            return this->price;
        }
        //////////////////////

        string to_string() {
            return format("Brend='{}', Color='{}', Width={}, Height={}, Price={}$", brend, color, width, height, price);
        }

        ushort surface_coating(ushort width, ushort height) {
            return (width / this->width) * (height / this->height);
        }

        float get_price(ushort count) {
            return count * this->price;
        }

};




int main()
{
    setlocale(LC_ALL, "");

    Tiles tiles;
    cout << tiles.to_string() << endl;    
    cout << format("Витрата на площу={}, Загальна вартість={}$", tiles.surface_coating(40, 100), tiles.get_price(144)) << endl;

}