#include "Car.h"
#include <iostream>

Car::Car(const string name, double rate) {
	carName=name;
	ratePerHour=rate;
}

const string Car::getCarName() const {
    return carName;
}

double Car::getRatePerHour() const {
    return ratePerHour;
}

void Car::displayDetails() const {
    cout << "- " << carName << "\nRate per Hour: $" << ratePerHour << "\n";
}

double Car::calculateFare(int hours) const {
    return ratePerHour * hours;
}

string Car::getCarType() const 
{
    return "Car";
}

Car::~Car() {}
