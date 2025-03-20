#include "Car.h"

Car::Car()
{
    model = "default";
    vendor = "noname";
    type = TC_CAR;
    _gasTank = 0;
    _fuel—onsumption = 0;
    _maxSpeed = 0;
}

Car::Car(string model, string vendor, TypeCar type, float gasTank, float fuel—onsumption, float maxSpeed)
{
    this->model = model;
    this->vendor = vendor;
    this->type = type;
    if (!setGasTank(gasTank)) _gasTank = 0;
    if (!setFuel—onsumption(fuel—onsumption)) _fuel—onsumption = 0;
    if (!setMaxSpeed(maxSpeed)) _maxSpeed = 0;
}

float Car::getGasTank()
{
    return _gasTank;
}

float Car::getFuel—onsumption()
{
    return _fuel—onsumption;
}

float Car::getMaxSpeed()
{
    return _maxSpeed;
}

bool Car::setGasTank(float gasTank)
{
    if (gasTank <= 0) return false;
    _gasTank = gasTank;
    return true;
}

bool Car::setFuel—onsumption(float fuel—onsumption)
{
    if (fuel—onsumption <= 0) return false;
    _fuel—onsumption = fuel—onsumption;
    return true;
}

bool Car::setMaxSpeed(float maxSpeed)
{
    if (maxSpeed <= 0) return false;
    _maxSpeed = maxSpeed;
    return true;
}

string Car::getTypeToString()
{
    switch (type)
    {
    case Car::TC_CAR: return "car";
        break;
    case Car::TC_TRUCK: return "truck";
        break;
    case Car::TC_PICKUP: return "pickup";
        break;
    case Car::TC_BUS: return "bus";
        break;
    case Car::TC_MINIBUS: return "minibus";
        break;    
    }
    return "car";
}

float Car::maxDistance()
{
    return _gasTank / _fuel—onsumption * 100;
}

string Car::toString()
{
    return vendor + " " + model + " (" + getTypeToString() + "), gas tank: " + 
        to_string(_gasTank) + ", fuel consumption: " + to_string(_fuel—onsumption) + 
        ", max speed: " + to_string(_maxSpeed);
}
