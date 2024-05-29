#include "CarRentalSystem.h"
#include "Car.cpp"
#include "Luxurycar.cpp"
#include "Economycar.cpp"
#include "Customer.cpp"

int main() 
{
	cout << "Project Created By : Furqan Rasheed ( 221427 ) \n";
	cout <<	"	             Muhammad Fahad ( 220362 ) " <<endl;
	cout << "\nWelcome to Car Rental System By F Group " << endl;
	cout << "--------------------------------"<<endl;
	
    CarRentalSystem rs;
    rs.displayMenu();
    return 0;
    
}

