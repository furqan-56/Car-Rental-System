#include "LuxuryCar.h"
#include <iostream>

LuxuryCar::LuxuryCar(const string name, double rate) : Car(name, rate) {}

void LuxuryCar::displayDetails() const {
    cout << "Luxury ";
    Car::displayDetails();
}

double LuxuryCar::calculateFare(int hours) const 
{
    return Car::calculateFare(hours) * 1.2;
}

string LuxuryCar::getCarType() const 
{
    return "Luxury";
}

