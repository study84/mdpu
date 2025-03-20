#pragma once
#include <string>

using namespace std;

class Car
{
public:
	string model;
	string vendor; // ��������
	enum TypeCar {
		TC_CAR,
		TC_TRUCK,
		TC_PICKUP,
		TC_BUS,
		TC_MINIBUS
	} type;
private:
	// �����
	float _gasTank;
	float _fuel�onsumption; //������ ������ �� 100 ��
	float _maxSpeed;

public:
	Car();
	Car(string model, string vendor, TypeCar type, float gasTank, float fuel�onsumption, float maxSpeed);

	float getGasTank();
	float getFuel�onsumption();
	float getMaxSpeed();
	bool setGasTank(float gasTank);
	bool setFuel�onsumption(float fuel�onsumption);
	bool setMaxSpeed(float maxSpeed);
	string getTypeToString();

	float maxDistance();
	string toString();
	
};

