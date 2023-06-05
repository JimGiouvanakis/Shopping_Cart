#ifndef ITEM_H
#define ITEM_H

class Item {
private:
    int itemNo;
    char itemDesc[21];
    float itemPrice;

public:
    Item();
    Item(int itemNo1, const char itemDesc1[], float itemPrice1);
    void readData();
    void setData(int itemNo1, const char itemDesc1[], float itemPrice1);
    void printData();
    int getItemNo();
    const char* getItemDesc();
    float getItemPrice();
};

#endif
