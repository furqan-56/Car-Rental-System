#ifndef LUXURYCAR_H
#define LUXURYCAR_H

#include "Car.h"

class LuxuryCar : public Car
{
    public:
        LuxuryCar(const string name, double rate);
        
        void displayDetails() const;
        
        double calculateFare(int hours) const;
        
        string getCarType() const;
};

#endif

