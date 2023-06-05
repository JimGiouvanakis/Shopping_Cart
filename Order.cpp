#include "Order.h"
#include <iostream>
#include <cstring>

Order::Order() : Customer(), Item() {
    orderNo = 0;
    orderDate[0] = '\0';
    totalAmount = 0.0;
}

Order::Order(int orderNo1, const char orderDate1[], float totalAmount1, int custNo1, const char custName1[], const char custEmail1[], int itemNo1, const char itemDesc1[], float itemPrice1) : Customer(custNo1, custName1, custEmail1), Item(itemNo1, itemDesc1, itemPrice1) {
    orderNo = orderNo1;
    strncpy(orderDate, orderDate1, 10);
    orderDate[10] = '\0';
    totalAmount = totalAmount1;
}

void Order::readData() {
    Customer::readData();
    std::cout << "Enter order number: ";
    std::cin >> orderNo;
    std::cin.ignore(); // Ignore the newline character
    std::cout << "Enter order date (yyyy-mm-dd): ";
    std::cin.getline(orderDate, 11);
}

void Order::setData(int orderNo1, const char orderDate1[], float totalAmount1, int custNo1, const char custName1[], const char custEmail1[], int itemNo1, const char itemDesc1[], float itemPrice1) {
    Customer::setData(custNo1, custName1, custEmail1);
    Item::setData(itemNo1, itemDesc1, itemPrice1);
    orderNo = orderNo1;
    strncpy(orderDate, orderDate1, 10);
    orderDate[10] = '\0';
    totalAmount = totalAmount1;
}

void Order::printData() {
    Customer::printData();
    Item::printData();
    std::cout << "Order number: " << orderNo << std::endl;
    std::cout << "Order date: " << orderDate << std::endl;
    std::cout << "Total amount: " << totalAmount << std::endl;
}

int Order::getOrderNo() {
    return orderNo;
}

const char* Order::getOrderDate() {
    return orderDate;
}

float Order::getTotalAmount() {
    return totalAmount;
}

void Order::buyItem(float price, int qty) {
    float amount = price * qty;
    totalAmount += amount;
}

int Order::shippingCost() {
    if (totalAmount > 200.0) {
        return 0;
    } else {
        return 20;
    }
}
