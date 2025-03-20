#pragma once
#include <string>

using namespace std;

class Car
{
public:
	string model;
	string vendor; // âèğîáíèê
	enum TypeCar {
		TC_CAR,
		TC_TRUCK,
		TC_PICKUP,
		TC_BUS,
		TC_MINIBUS
	} type;
private:
	// ïğîá³ã
	float _gasTank;
	float _fuelÑonsumption; //ğàñõîä ïàëèâà íà 100 êì
	float _maxSpeed;

public:
	Car();
	Car(string model, string vendor, TypeCar type, float gasTank, float fuelÑonsumption, float maxSpeed);

	float getGasTank();
	float getFuelÑonsumption();
	float getMaxSpeed();
	bool setGasTank(float gasTank);
	bool setFuelÑonsumption(float fuelÑonsumption);
	bool setMaxSpeed(float maxSpeed);
	string getTypeToString();

	float maxDistance();
	string toString();
	
};

