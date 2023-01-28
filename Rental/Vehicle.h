#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <algorithm>
using namespace std;

class Vehicle {
public:
	Vehicle(string Type, string RegNum, string Make, string Model, int Age);
	~Vehicle();
	void MenuDisplay() const;
	void SerchDisplay() const;

	//getter
	string GetType() const { return Type; };
	string GetRegNum() const { return RegNum; };
	string GetCMake() const { return Cmake; };
	string GetModel() const { return Model; };
	int GetAge() const { return Age; };
	int GetCostPerDay() const { return CostPerDay(); };

	void displaymake() const { cout << Cmake << "\n"; };//Display char make

private:
	string Type, RegNum, Make, Model;
	int Age;
	char* Cmake;//pointer make

protected:
	virtual int CostPerDay() const = 0;
	
};

