#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
private:
    int custNo;
    char custName[21];
    char custEmail[21];

public:
    Customer();
    Customer(int custNo1, const char custName1[], const char custEmail1[]);
    void readData();
    void setData(int custNo1, const char custName1[], const char custEmail1[]);
    void printData();
    int getCustNo();
    const char* getCustName();
    const char* getCustEmail();
};

#endif


