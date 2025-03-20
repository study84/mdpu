
#include <iostream>
#include "Car.h"

int main()
{
    Car car1;
    cout << car1.toString() << endl;
    Car* car2 = new Car("Rander", "Ford", Car::TC_PICKUP, 80, 12, 167);
    cout << car2->toString() << endl;
    cout << "Max distance: " << car2->maxDistance() << endl;
}
