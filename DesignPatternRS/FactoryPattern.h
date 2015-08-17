#pragma once

#include <iostream>
#include <string>

class Car
{
public:
	Car() {}
	Car(int doors, double pwr, double tq) : doorCount(doors), power(pwr), torque(tq) {}
protected:
	int doorCount;
	double power, torque;
};

class SportsCar : public Car
{
public:
	SportsCar() {}
	SportsCar(int doors, double pwr, double tq, bool coupe) : isCoupe(coupe) { doorCount = doors; power = pwr; torque = tq; }
private:
	bool isCoupe;
};

class PickupTruck : public Car
{
public:
	PickupTruck() {}
	PickupTruck(int doors, double pwr, double tq, bool manly) : isManly(manly) { doorCount = doors; power = pwr; torque = tq; }
private:
	bool isManly;
};

class CarFactory
{
public:
	Car *createCar(std::string type)
	{
		if (type == "SportsCar") {
			return new PickupTruck(2, 520, 400, true);
		}
		else if (type == "PickupTruck") {
			return new PickupTruck(4, 255, 600, false);
		}
		else {
			return nullptr;
		}
	}
};

/*
CarFactory factory;
factory.createCar("SportsCar");
factory.createCar("PickupTruck");
*/