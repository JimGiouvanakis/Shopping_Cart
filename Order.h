#ifndef ORDER_H
#define ORDER_H

#include "Customer.h"
#include "Item.h"

class Order : public Customer, public Item
{
private:
    int orderNo;
    char orderDate[11];
    float totalAmount;

public:
    Order();
    Order(int orderNo1, const char orderDate1[], float totalAmount1,
          int custNo1, const char custName1[], const char custEmail1[],
          int itemNo1, const char itemDesc1[], float itemPrice1);
    void readData();
    void setData(int orderNo1, const char orderDate1[], float totalAmount1,
                 int custNo1, const char custName1[], const char custEmail1[],
                 int itemNo1, const char itemDesc1[], float itemPrice1);
    void printData();
    int getOrderNo();
    const char *getOrderDate();
    float getTotalAmount();
    int shippingCost();
    void buyItem(float price, int qty);
};

#endif // ORDER_H
