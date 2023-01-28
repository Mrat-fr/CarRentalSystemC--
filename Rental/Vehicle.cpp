#include "Vehicle.h"

Vehicle::Vehicle(string Type, string RegNum, string Make, string Model, int Age) :
	Type(Type), RegNum(RegNum), Make(Make), Model(Model), Age(Age) {

	int size = Make.length() + 1;
	Cmake = (char*)realloc(Cmake, sizeof(char) * size);//change the size of char array

	for (int i = 0; i < size; i++) {//put the string make too the char array
		Cmake[i] = Make[i];
	}
}

Vehicle::~Vehicle(){
	delete Cmake;//delete the char make so no data leak
	Cmake = nullptr;
}

void Vehicle::MenuDisplay() const{
	int Price = CostPerDay();
	cout << RegNum << "\t\t" << char(156) << CostPerDay() << "\t\t" << Type << "\n"; //for the main menu
}

void Vehicle::SerchDisplay() const{
	int Price = CostPerDay();
	cout << RegNum << "\t\t" << char(156) << CostPerDay() << "\t\t" << Cmake << "\t\t" << Model << "\n"; //display search results
}