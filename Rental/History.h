#pragma once
#include <iostream>
#include <string>
using namespace std;

class History
{
public:
	History(string RentDayFrom, string RentDayTo, int RentDays, int TotalCost, int CustomerNumber, string CustomerName, string CustomerAddress);

	void Display() const;
	string writefile() const;

	//getters
	int GetTotalCost() const;
	int GetRentDays() const;


private:
	int RentDays, TotalCost, CustomerNumber;
	string RentDayFrom, RentDayTo, CustomerName, CustomerAddress;

};

