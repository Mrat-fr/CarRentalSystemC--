#pragma once
#include "Vehicle.h"
class Car : public Vehicle {
public:
	Car(string Type, string RegNum, string Make, string Model, int Age, int NumOfSeats, int NumOfDoors);

	//getter
	int GetNumOfSeats() const { return NumOfSeats; };
	int GetNumOfDoors() const { return NumOfDoors; };

private:
	int NumOfSeats, NumOfDoors;

protected:
	virtual int CostPerDay() const override;//override chnage the value of the function
};

