#include "Car.h"

Car::Car(string Type, string RegNum, string Make, string Model, int Age, int NumOfSeats, int NumOfDoors)
	:Vehicle(Type, RegNum, Make, Model, Age), NumOfSeats(NumOfSeats), NumOfDoors(NumOfDoors) {
}


int Car::CostPerDay() const {
	int Cost = (2500 - (GetAge() * 150) - (NumOfDoors * 200));
	int Val = Cost / 100;
	if (Val < 10)
		Val = 10;
	return Val;
}
