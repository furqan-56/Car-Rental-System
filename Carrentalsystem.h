#ifndef CARRENTALSYSTEM_H
#define CARRENTALSYSTEM_H

#include "Car.h"
#include "LuxuryCar.h"
#include "EconomyCar.h"
#include "Customer.h"
#include <fstream>
#include <iostream>

class CarRentalSystem
{
    private :
        Car* cars[10];
        int numCars;
        Customer* customer;
    
    public :
      
CarRentalSystem() {
	numCars=0;
    readCarDataFromFile("car_data.txt");
}

~CarRentalSystem() {
    for (int i = 0; i < numCars; ++i) {
        delete cars[i];
    }
}

void displayMenu() {
    int choice;
    do {
        cout << "\nCar Rental Menu:\n"
             << "1. Display Cars\n"
             << "2. Rent a Car\n"
             << "3. Save Cars to File\n"
             << "4. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        cout<<endl;

        switch (choice) {
            case 1:
                for (int i = 0; i < numCars; ++i) {
                    cout << i + 1 << ". ";
                    cars[i]->displayDetails();
                }
                break;
            case 2: {
                int carIndex;
                double hours;
                cout << "Enter car index and rental hours: ";
                cin >> carIndex >> hours;
                rentCar(carIndex - 1, hours);
                break;
            }
            case 3:
                saveCarsToFile();
                break;
            case 4:
                saveCarsToFile();
                cout << "Exiting the program.\n";
                cout << "--------------------------------"<<endl;
                cout << "\nProject Created By : Furqan Rasheed ( 221427 ) \n";
				cout <<	"	             Muhammad Fahad ( 220362 ) "<<endl;
				cout << "Thanks to visit Car Rental System By F Group " << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);
}

void rentCar(int carIndex, double hours) {
    if (carIndex >= 0 && carIndex < numCars) {
        string name, phoneNumber, address;
        cin.ignore();  
        cout << "Enter your full name: ";
        getline(cin, name);
        cout << "Enter your phone number: ";
        getline(cin, phoneNumber);
        cout << "Enter your address: ";
        getline(cin, address);
        customer = new Customer(name, phoneNumber, address);  

        double fare = cars[carIndex]->calculateFare(hours);
        cout << "\n\n****************** Car Rental Invoice ******************\n";
        cout << "Customer Name: " << customer->getName() << "\n";
        cout << "Phone Number: " << customer->getPhoneNumber() << "\n";
        cout << "Address: " << customer->getAddress() << "\n";
        cout << endl;
        cout << "Car Rented Type : ";
        cars[carIndex]->displayDetails();
        cout << "Total Fare: $" << fare << "\n";
        cout << endl;
        cout << "Thank you for choosing our car rental service!\n";
        cout << "********************************************************\n\n";
    } else {
        cout << "Invalid car selection.\n";
    }
}

void saveCarsToFile() const {
    ofstream file("car_data.txt");
    if (file.is_open()) {
        for (int i = 0; i < numCars; ++i) {
            file << cars[i]->getCarType() << " " << cars[i]->getCarName() << " " << cars[i]->getRatePerHour() << "\n";
        }
        file.close();
        cout << "Cars data saved to file.\n";
    } else {
        cerr << "Unable to open file for saving.\n";
    }
}

void readCarDataFromFile(const string& filename) {
    ifstream file("car_data.txt");
    if (file.is_open()) {
        while (file >> ws, !file.eof()) {
            string carType;
            string carName;
            double rate;
            file >> carType >> carName >> rate;

            if (numCars < 10) {
                if (carType == "Luxury") {
                    cars[numCars++] = new LuxuryCar(carName, rate);
                } else if (carType == "Economy") {
                    cars[numCars++] = new EconomyCar(carName, rate);
                }
            } else {
                cout << "Warning: Maximum number of cars reached. Skipping additional entries.\n";
                break;
            }
        }
        file.close();
    } else {
        cout << "Unable to open file: " << filename << "\n";
    }
}

};

#endif

