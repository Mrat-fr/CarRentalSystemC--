#pragma once
#include "Vehicle.h"
#include "History.h"
class Record{
public:
	~Record();

	void Load(string Name);
	void Add(int cost);
	void ViewRecord();
	void Exit(string Name);

	int TotalRentalIncome();
	int TotalDaysRented();

private:
	int TRentalIncome, TDaysRented, RentalIndex;
	int heapline;//track the size of object heap array
	History** VehicleHistory = new History*;	

};

