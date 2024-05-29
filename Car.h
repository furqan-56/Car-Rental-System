#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car
{
    private :
        string carName;
        double ratePerHour;
    
    public :
    	Car(){
    		carName="";
         	ratePerHour=0.0;
		}
        Car(const string name, double rate);
        const string getCarName() const;
        double getRatePerHour() const;
        virtual void displayDetails() const;
        virtual double calculateFare(int hours) const;
        virtual ~Car();
        virtual string getCarType() const;
};

#endif

