#include "Customer.h"

Customer::Customer(const string& name, const string& phoneNumber, const string& address)
    : name(name), phoneNumber(phoneNumber), address(address) {}

const string& Customer::getName() const {
    return name;
}

const string& Customer::getPhoneNumber() const {
    return phoneNumber;
}

const string& Customer::getAddress() const {
    return address;
}

