#include "Customer.h"
#include <iostream>
#include <cstring>

Customer::Customer() {
    custNo = 0;
    custName[0] = '\0';
    custEmail[0] = '\0';
}

Customer::Customer(int custNo1, const char custName1[], const char custEmail1[]) {
    custNo = custNo1;
    strncpy(custName, custName1, 20);
    custName[20] = '\0';
    strncpy(custEmail, custEmail1, 20);
    custEmail[20] = '\0';
}

void Customer::readData() {
    std::cout << "Enter customer number: ";
    std::cin >> custNo;
    std::cin.ignore(); // Ignore the newline character
    std::cout << "Enter customer name: ";
    std::cin.getline(custName, 21);
    std::cout << "Enter customer email: ";
    std::cin.getline(custEmail, 21);
}

void Customer::setData(int custNo1, const char custName1[], const char custEmail1[]) {
    custNo = custNo1;
    strncpy(custName, custName1, 20);
    custName[20] = '\0';
    strncpy(custEmail, custEmail1, 20);
    custEmail[20] = '\0';
}

void Customer::printData() {
    std::cout << "Customer number: " << custNo << std::endl;
    std::cout << "Customer name: " << custName << std::endl;
    std::cout << "Customer email: " << custEmail << std::endl;
}

int Customer::getCustNo() {
    return custNo;
}

const char* Customer::getCustName() {
    return custName;
}

const char* Customer::getCustEmail() {
    return custEmail;
}
