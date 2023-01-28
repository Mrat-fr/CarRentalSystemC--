#include "Bike.h"

Bike::Bike(string Type, string RegNum, string Make, string Model, int Age, int EngineSize, int NumOfWheels)
	:Vehicle(Type, RegNum, Make, Model, Age), EngineSize(EngineSize), NumOfWheels(NumOfWheels) {
}

int Bike::CostPerDay() const {
	int Cost = (1500 + (100 * ((EngineSize + 99) / 100)));
	int Val = Cost / 100;
	if (Val < 10)
		Val = 10;
	return Val;
}
