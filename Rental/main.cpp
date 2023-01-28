#include <iostream>
#include "Rental.h"
using namespace std;

int main() {
	#ifdef _DEBUG //check for memory leaks
		// _CrtSetBreakAlloc(449);
		_onexit(_CrtDumpMemoryLeaks);
	#endif

	Rental R;//All the funaction are stored in this class
	int op;
	R.Load();//load the info from file to the system
	do {
		cout << "Vehicle Rental System\n";
		cout << "---------------------\n\n";
		cout << "Registration Number     Cost Per Day	Vehicle Type\n";
		cout << "-------------------     ------------    ------------\n";
		R.Display();//show rental vehicle from vector
		cout << "1) Add vehicle\n";
		cout << "2) Remove vehicle\n";
		cout << "3) Search for car\n";
		cout << "4) Search for bike\n";
		cout << "5) Sort vehicles by registration number\n";
		cout << "6) Sort by cost per day\n";
		cout << "9) Exit\n";
		cout << "/ ";
		cin >> op;
		switch (op) {
			case 1:R.Add(); break;
			case 2:R.Remove(); break;
			case 3:R.SearchForCar(); break;
			case 4:R.SearchForBike(); break;
			case 5:R.SortReg(); break;
			case 6:R.SortCostPerDay(); break;
			case 9:R.Exit(); break;//get the info from vector and put on the file
			default: cout << "Please pick one of the options:\n";
		}
	} while (op != 9);
	return 0;
}