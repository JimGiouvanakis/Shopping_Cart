#include "Item.h"
#include <iostream>
#include <cstring>

Item::Item() {
    itemNo = 0;
    itemDesc[0] = '\0';
    itemPrice = 0.0;
}

Item::Item(int itemNo1, const char itemDesc1[], float itemPrice1) {
    itemNo = itemNo1;
    strncpy(itemDesc, itemDesc1, 20);
    itemDesc[20] = '\0';
    itemPrice = itemPrice1;
}

void Item::readData() {
    std::cout << "Enter item number: ";
    std::cin >> itemNo;
    std::cin.ignore(); // Ignore the newline character
    std::cout << "Enter item description: ";
    std::cin.getline(itemDesc, 21);
    std::cout << "Enter item price: ";
    std::cin >> itemPrice;
}

void Item::setData(int itemNo1, const char itemDesc1[], float itemPrice1) {
    itemNo = itemNo1;
    strncpy(itemDesc, itemDesc1, 20);
    itemDesc[20] = '\0';
    itemPrice = itemPrice1;
}

void Item::printData() {
    std::cout << "Item number: " << itemNo << std::endl;
    std::cout << "Item description: " << itemDesc << std::endl;
    std::cout << "Item price: " << itemPrice << std::endl;
}

int Item::getItemNo() {
    return itemNo;
}

const char* Item::getItemDesc() {
    return itemDesc;
}

float Item::getItemPrice() {
    return itemPrice;
}
