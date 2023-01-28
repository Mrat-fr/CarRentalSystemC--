#include "History.h"

History::History(string RentDayFrom, string RentDayTo, int RentDays, int TotalCost, int CustomerNumber, string CustomerName, string CustomerAddress)
	:RentDayFrom(RentDayFrom), RentDayTo(RentDayTo), RentDays(RentDays), TotalCost(TotalCost), CustomerNumber(CustomerNumber), CustomerName(CustomerName), CustomerAddress(CustomerAddress)
{
}

void History::Display() const{
	cout << "Date From:           " << RentDayFrom << "\n";
	cout << "Date To:             " << RentDayTo << "\n";
	cout << "Rental Days:         " << RentDays << "\n";
	cout << "Total Cost:          " << char(156) << TotalCost << "\n";
	cout << "Customer Name:       " << CustomerName << "\n";
	cout << "Customer Address:    " << CustomerAddress << "\n";
	cout << "Customer Number:     " << CustomerNumber << "\n\n";
}

string History::writefile() const{
	string SRentDays = to_string(RentDays);
	string STotalCost = to_string(TotalCost);
	string SCustomerNumber = to_string(CustomerNumber);
	string write = RentDayFrom + "|" + RentDayTo + "|" + SRentDays + "|" + STotalCost + "|" + SCustomerNumber + "|" + CustomerName + "|" + CustomerAddress;
	return write;
}

int History::GetTotalCost() const{return TotalCost;}

int History::GetRentDays() const{return RentDays;}
