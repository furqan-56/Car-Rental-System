#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer
{
    private:
        string name;
        string phoneNumber;
        string address;

    public:
        Customer(const string& name, const string& phoneNumber, const string& address);
        const string& getName() const;
        const string& getPhoneNumber() const;
        const string& getAddress() const;
};

#endif

