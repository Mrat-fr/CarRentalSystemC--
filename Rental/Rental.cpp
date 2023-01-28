#include "Rental.h"

Rental::~Rental(){
    for (int i = 0; i < VehicleList.size(); ++i)
        delete VehicleList[i];//delete vector

    VehicleList.clear();   //clear vector pointer (no memory leak)


}

void Rental::Add() {//Add a car or bike the the system
    string type, reg, model, make;
    int op, age, numofdoor, numofseats, enginesize, numofwheels;
    cout << "Enter Type of Vehicle: \n";
    cout << "1) Car \n";
    cout << "2) Bike\n";
    cin >> op;
    
    cout << "Enter Registeration Number: ";
    getline(cin, reg);//two cin for space
    getline(cin, reg);
    for (int i = 0; i < VehicleList.size(); ++i){//check if the reg is unique
        if (VehicleList[i]->GetRegNum() == reg) {
            cout << "Registeration Number Already in the system\n\n";
            return;
        }
    }
    cout << "Enter Make: ";
    cin >> make;

    cout << "Enter Model: ";
    cin >> model;

    cout << "Enter Age: ";
    cin >> age;

    if (op == 1) {//switch if they want a car or bike
        type = "Car";
        cout << "Enter Number of Doors: ";
        cin >> numofdoor;
        cout << "Enter Number of Seats: ";
        cin >> numofseats;
        VehicleList.push_back(new Car(type, reg, make, model, age, numofseats, numofdoor));//push into a vector on the heap
        cout << "Car Added\n";
    } else if (op == 2) {
        type = "Bike";
        cout << "Enter Engine Size: ";
        cin >> enginesize;
        cout << "Enter Number of wheels: ";
        cin >> numofwheels;
        VehicleList.push_back(new Bike(type, reg, make, model, age, enginesize, numofwheels));
        cout << "Bike Added\n";
    }
    ofstream outfile(reg +=".txt");//creat a file for history
    outfile.close();
}

void Rental::Load(){//edit more 
    ifstream file("Vehicles.txt");
    string line, type, reg, make, model, age, doors, seats, engine, wheels;
    while (getline(file, line)) {//run though each line until the end
        stringstream ss(line);
        getline(ss, type, '|');
        getline(ss, reg, '|');
        getline(ss, make, '|');
        getline(ss, model, '|');
        getline(ss, age, '|');
        if (type == "Car") {
            getline(ss, seats, '|');
        }
        else {
            getline(ss, engine, '|');
        }
        if (type == "Car") {
            getline(ss, doors, '|');
        }
        else {
            getline(ss, wheels, '|');
        }

        if (type == "Car") {
            VehicleList.push_back(new Car(type, reg, make, model, stoi(age), stoi(seats), stoi(doors)));
        }
        else if (type == "Bike") {
            VehicleList.push_back(new Bike(type, reg, make, model, stoi(age), stoi(engine), stoi(wheels)));
        }
    }
}

void Rental::Display(){//Display for main menu 
    for (int i = 0; i < VehicleList.size(); ++i){
        VehicleList[i]->MenuDisplay();
    }
    cout << "\n";
}

void Rental::Remove(){
    string reg;
   cout << "Enter Registeration Number: ";
   getline(cin, reg);
   getline(cin, reg);
   for (int i = 0; i < VehicleList.size(); ++i){
       if (VehicleList[i]->GetRegNum() == reg) {
            delete VehicleList[i];
            VehicleList.erase(VehicleList.begin() + i);
            cout << "Vehicle Removed\n";
            return;
       }
   }
   cout << "Vehicle Not Found\n";
}

void Rental::SearchForCar() {
    int op, option;
    int count = 0;
    int loop = 0;
    vector<string> RegNum;
    cout << "Search for a car by:\n";
    cout << "--------------------\n";
    cout << "1) Registration number\n";
    cout << "2) Number of seats\n";
    cout << "3) Number of doors\n";
    cout << "9) Return to main menu\n\n";
    cout << "Please choose an option:\n";
    while (loop == 0) {
        cout << "/ ";
        cin >> op;
        if (op == 1 || op == 2 || op == 3 || op == 9) {
            loop = 1;
        }
        else {
            cout << "Pick one of the options\n";
        }
    }
   
    switch(op){
        case 1: {
            string reg;
            cout << "Enter Registration number:";
            getline(cin, reg);
            getline(cin, reg);
            cout << "\nList of cars matching that search :\n\n";
            cout << "	Registration Number     Cost Per Day	  Make     Model\n";
            cout << "	-------------------     -------------     ----     -----\n";
            for (int i = 0; i < VehicleList.size(); ++i) {
                if (VehicleList[i]->GetType() == "Car") {
                    if (VehicleList[i]->GetRegNum() == reg) {
                        ++count;
                        cout << count << "	";
                        VehicleList[i]->SerchDisplay();
                        string reg = VehicleList[i]->GetRegNum();
                        RegNum.push_back(reg);
                    }
                }
            }
        }; break;
        case 2: {
            int seat;
            cout << "Enter number of seats:";
            cin >> seat;
            cout << "\nList of cars matching that search :\n\n";
            cout << "	Registration Number     Cost Per Day	  Make     Model\n";
            cout << "	-------------------     -------------     ----     -----\n";
            for (int i = 0; i < VehicleList.size(); ++i) {
                if (VehicleList[i]->GetType() == "Car") {
                     if (dynamic_cast<const Car*>(VehicleList[i])->GetNumOfSeats() == seat) {//dynamic cast to get funcation in the subclass
                        ++count;
                        cout << count << "	";
                        VehicleList[i]->SerchDisplay();
                        string reg = VehicleList[i]->GetRegNum();
                        RegNum.push_back(reg);
                    }
                }
            }
        }; break;
        case 3: {
            int door;
            cout << "Enter number of doors:";
            cin >> door;
            cout << "\nList of cars matching that search :\n\n";
            cout << "	Registration Number     Cost Per Day	  Make     Model\n";
            cout << "	-------------------     -------------     ----     -----\n";
            for (int i = 0; i < VehicleList.size(); ++i) {
                if (VehicleList[i]->GetType() == "Car") {
                    if (dynamic_cast<const Car*>(VehicleList[i])->GetNumOfDoors() == door) {
                    ++count;
                    cout << count << "	";
                    VehicleList[i]->SerchDisplay();
                    string reg = VehicleList[i]->GetRegNum();
                    RegNum.push_back(reg);
                    }
                }
            }
        }; break;
    }
    cout << "\nEnter number to choose vehicle or 0 to return to main menu:\n";//user pick what to look at
    int vloop = 0;
    while(vloop == 0){
        cout << "/ ";
        cin >> option;
        if (option == 0) {
            return;
        }
        if (option <= count) {
            History(RegNum, option);//pointer?
            return;
        }
       cout << "Pick a valid input\n";
    }
}

void Rental::SearchForBike(){
    int op, option;
    int count = 0;
    int loop = 0;
    vector<string> RegNum;
    cout << "Search for a Bike by:\n";
    cout << "--------------------\n";
    cout << "1) Registration number\n";
    cout << "2) Max engine size\n";
    cout << "3) Number of Wheels\n";
    cout << "9) Return to main menu\n\n";
    cout << "Please choose an option:\n";
    while (loop == 0) {
        cout << "/ ";
        cin >> op;
        if (op == 1 || op == 2 || op == 3 || op == 9) {
            loop = 1;
        }
        else {
            cout << "Pick one of the options\n";
        }
    }

    switch (op) {
        case 1: {
            string reg;
            cout << "Enter Registration number:";
            getline(cin, reg);
            getline(cin, reg);
            cout << "\nList of cars matching that search :\n\n";
            cout << "	Registration Number     Cost Per Day	  Make     Model\n";
            cout << "	-------------------     -------------     ----     -----\n";
            for (int i = 0; i < VehicleList.size(); ++i) {
                if (VehicleList[i]->GetType() == "Bike") {
                    if (VehicleList[i]->GetRegNum() == reg) {
                        ++count;
                        cout << count << "	";
                        VehicleList[i]->SerchDisplay();
                        string reg = VehicleList[i]->GetRegNum();
                        RegNum.push_back(reg);
                    }
                }
            }
        }; break;
        case 2: {
            int engine;
            cout << "Enter max engine size:";
            cin >> engine;
            cout << "\nList of cars matching that search :\n\n";
            cout << "	Registration Number     Cost Per Day	  Make     Model\n";
            cout << "	-------------------     -------------     ----     -----\n";
            for (int i = 0; i < VehicleList.size(); ++i) {
                if (VehicleList[i]->GetType() == "Bike") {
                    if (dynamic_cast<const Bike*>(VehicleList[i])->GetEngineSize() == engine) {
                        ++count;
                        cout << count << "	";
                        VehicleList[i]->SerchDisplay();
                        string reg = VehicleList[i]->GetRegNum();
                        RegNum.push_back(reg);
                    }
                }
            }
        }; break;
        case 3: {
            int wheel;
            cout << "Number of Wheels:";
            cin >> wheel;
            cout << "\nList of cars matching that search :\n\n";
            cout << "	Registration Number     Cost Per Day	  Make     Model\n";
            cout << "	-------------------     -------------     ----     -----\n";
            for (int i = 0; i < VehicleList.size(); ++i) {
                if (VehicleList[i]->GetType() == "Bike") {
                    if (dynamic_cast<const Bike*>(VehicleList[i])->GetNumOfWheels() == wheel) {
                        ++count;
                        cout << count << "	";
                        VehicleList[i]->SerchDisplay();
                        string reg = VehicleList[i]->GetRegNum();
                        RegNum.push_back(reg);
                    }
                }
            }
        }; break;
    }
    cout << "\nEnter number to choose vehicle or 0 to return to main menu:\n";//user pick what to look at
    int vloop = 0;
    while (vloop == 0) {
        cout << "/ ";
        cin >> option;
        if (option == 0) {
            return;
        }
        if (option <= count) {
            History(RegNum, option);
            return;
        }
        cout << "Pick a valid input\n";
    }
}

void Rental::History(vector<string> Reg, int option){
    Record Rec;
    string RegNum = Reg[option - 1];
    Rec.Load(RegNum);
    for (int i = 0; i < VehicleList.size(); ++i) {
        if (VehicleList[i]->GetRegNum() == RegNum) {
            int loop = 0;
            int op;
            while (loop == 0) {
            cout << "\n" << VehicleList[i]->GetRegNum() << ": " << VehicleList[i]->GetCMake() << " " << VehicleList[i]->GetModel() << "\n";
            cout << "--------------------------------\n";
            cout << "Cost Per Day:            " << char(156) << VehicleList[i]->GetCostPerDay() << "\n";
            cout << "Total Rental Income:     " << char(156) << Rec.TotalRentalIncome() << "\n";
            cout << "Total Days Rented:       " << Rec.TotalDaysRented() <<"\n\n";
            cout << "1) Rent Vehicle \n";
            cout << "2) View historic rentals \n";
            cout << "9) Return to main menu \n\n";
            cout << "Please choose an option:\n";
                cout << "/ ";
                cin >> op;
                if (op == 1) {
                    Rec.Add(VehicleList[i]->GetCostPerDay());
                }
                else if (op == 2) {
                    cout << VehicleList[i]->GetRegNum() << ": " << VehicleList[i]->GetCMake() << " " << VehicleList[i]->GetModel() << " Rental History" << "\n";
                    cout << "--------------------------------\n";
                    Rec.ViewRecord();
                }
                else if (op == 9) {
                    Rec.Exit(RegNum);
                    loop = 1;
                }
                else
                    cout << "Pick a valid input\n";
            }
        }
    }
}

//bool CompareReg(const Vehicle* a, const Vehicle* b) { return (a->GetRegNum() < b->GetRegNum()); } 

void Rental::SortReg(){
    sort(VehicleList.begin(), VehicleList.end(), [](const Vehicle* a, const Vehicle* b) -> bool{return a->GetRegNum() < b->GetRegNum();});;
}

void Rental::SortCostPerDay() {
    sort(VehicleList.begin(), VehicleList.end(), [](const Vehicle* a, const Vehicle* b) -> bool {return a->GetCostPerDay() < b->GetCostPerDay(); });;
}


void Rental::Exit(){
    ofstream file("Vehicles.txt");
    for (int i = 0; i < VehicleList.size(); ++i){
        if (VehicleList[i]->GetType() == "Car") {
            const Car* car = dynamic_cast<const Car*>(VehicleList[i]);// use car class functions
            file << car->GetType() << "|" << car->GetRegNum() << "|" << car->GetCMake() << "|" << car->GetModel() << "|" << car->GetAge() << "|" << car->GetNumOfSeats() << "|" << car->GetNumOfDoors() << "\n";
        }

        if (VehicleList[i]->GetType() == "Bike") {
            const Bike* bike = dynamic_cast<const Bike*>(VehicleList[i]);
            file << bike->GetType() << "|" << bike->GetRegNum() << "|" << bike->GetCMake() << "|" << bike->GetModel() << "|" << bike->GetAge() << "|" << bike->GetEngineSize() << "|" << bike->GetNumOfWheels() << "\n";
        }
    }

    file.close();
}
