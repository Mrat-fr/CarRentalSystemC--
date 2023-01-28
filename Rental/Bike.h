#pragma once
#include "Vehicle.h"
class Bike : public Vehicle {
public:
	Bike(string Type, string RegNum, string Make, string Model, int Age, int EngineSize, int NumOfWheels);

	//getter
	int GetEngineSize() const { return EngineSize; };
	int GetNumOfWheels() const { return NumOfWheels; };

private:
	int EngineSize, NumOfWheels;

protected:
	virtual int CostPerDay() const override;//override chnage the value of the function
};

