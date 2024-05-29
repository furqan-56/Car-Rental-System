#ifndef ECONOMYCAR_H
#define ECONOMYCAR_H

#include "Car.h"

class EconomyCar : public Car
{
    public :
        EconomyCar(const string name, double rate);
        
        void displayDetails() const ;
        
        string getCarType() const ;
};

#endif

