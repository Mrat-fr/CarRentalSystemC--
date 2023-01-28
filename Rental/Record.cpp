#include "Record.h"

Record::~Record(){
    for (int i = 0; i < heapline; i++)
        delete VehicleHistory[i];

    delete[] VehicleHistory;
    VehicleHistory = nullptr;
}

void Record::Load(string Name){
    ifstream file(Name += ".txt");
    heapline = 0;
    string line, rentdayfrom, rentdayto, rentdays, totalcost, customernumber, customername, customeraddress;
    while (getline(file, line)) {//run though each line until the end
        stringstream ss(line);
        getline(ss, rentdayfrom, '|');
        getline(ss, rentdayto, '|');
        getline(ss, rentdays, '|');
        getline(ss, totalcost, '|');
        getline(ss, customernumber, '|');
        getline(ss, customername, '|');

        VehicleHistory[heapline] = new History(rentdayfrom, rentdayto, stoi(rentdays), stoi(totalcost), stoi(customernumber), customername, customeraddress);
        heapline++;// line number and for new object
        VehicleHistory = (History**)realloc(VehicleHistory, sizeof(History) * heapline);//resize it to fit more history
    }
}

void Record::Add(int cost){
    int rentday = 10;
    int custnum, totalcost;
    string rentdate, dateto, custname, custaddres;
    cout << "Renting\n";
    cout << "-----------------\n";
    cout << "Full Name: ";
    cin.ignore();
    getline(cin, custname);
    cout << "Phone Number: ";
    cin >> custnum;
    cout << "Address: ";
    cin.ignore();
    getline(cin, custaddres);
    cout << "Rent Date (DD MMM YYYY):";
    getline(cin, rentdate);
    cout << "Return Date (DD MMM YYYY):";
    getline(cin, dateto);
    cout << "How many days:";
    cin >> rentday;

    totalcost = cost * rentday;

    VehicleHistory[heapline] = new History(rentdate, dateto, rentday, totalcost, custnum, custname, custaddres);
    heapline++;
    VehicleHistory = (History**)realloc(VehicleHistory, sizeof(History) * heapline);//resize it to fit info
}

void Record::ViewRecord(){
    int op;
    if (heapline > 0) {
        for (int i = 0; i < heapline; ++i) {
            cout << "Rental:              " << i + 1 << " of " << heapline << "\n";
            VehicleHistory[i]->Display();
            cout << "1) View the previous record\n";
            cout << "2) View the next record\n";
            cout << "9) Return to vehicle information screen\n\n";
            cout << "Please choose an option: \n";
            int vloop = 0;
            while (vloop == 0) {
                cout << "/ ";
                cin >> op;
                if (op == 1)
                    if (i > 0) {
                        if (i != 0) {
                            i = i - 2;
                        }
                        vloop = 1;
                    }
                    else
                        cout << "This is first record\n";
                else if (op == 2)
                    if (i+1 >= heapline) {
                        cout << "No more next records\n";
                    }
                    else
                        vloop = 1;

                else if (op == 9)
                    return;
                else
                    cout << "Pick a valid input\n";
            }
        }
    }
    else {
        cout << "No Rental Records.\n\n";
    }
}

void Record::Exit(string Name){//write to the file
    ofstream file(Name += ".txt");
    for (int i = 0; i < heapline; ++i) {
        file << VehicleHistory[i]->writefile() << "\n";
    }
    file.close();
}

int Record::TotalRentalIncome(){//add up total income
    TRentalIncome = 0;
    for (int i = 0; i < heapline; ++i) {
        TRentalIncome = TRentalIncome + VehicleHistory[i]->GetTotalCost();
    }
    return TRentalIncome;
}

int Record::TotalDaysRented(){//add up total days
    TDaysRented = 0;
    for (int i = 0; i < heapline; ++i) {
        TDaysRented = TDaysRented + VehicleHistory[i]->GetRentDays();
    }
    return TDaysRented;
}


