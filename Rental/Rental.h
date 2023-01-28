#pragma once
#include "Bike.h"
#include "Car.h"
#include "Record.h"

class Rental {
public:
	~Rental();

	void Add();
	void Load();
	void Display();
	void Remove();
	void SearchForCar();
	void SearchForBike();
	void History(vector<string> Reg, int option);
	void SortReg();
	void SortCostPerDay();
	void Exit();

private:
	vector<const Vehicle*> VehicleList;

};

