#include "EconomyCar.h"
#include <iostream>

EconomyCar::EconomyCar(const string name, double rate) : Car(name, rate) {}

void EconomyCar::displayDetails() const 
{
    cout << "Economy ";
    Car::displayDetails();
    
}

string EconomyCar::getCarType() const 
{
    return "Economy";
}

