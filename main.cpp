#include "Item.h"
#include "Order.h"
#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_PRODUCTS = 100;

int fileToArr(std::ifstream &fin, Item p[])
{
    int numProducts = 0;

    int itemNo;
    char itemDesc[21];
    float itemPrice;
    while (fin >> itemNo >> itemDesc >> itemPrice)
    {
        p[numProducts].setData(itemNo, itemDesc, itemPrice);
        numProducts++;
    }
    return numProducts;
}

int itemMenu(Item p[], int n)
{

    int itemCode;

    std::cout << "\nLISTA DIATHESIMWN PROTONTWN" << std::endl;
    std::cout << "===========================" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << p[i].getItemNo() << ", " << p[i].getItemDesc() << ", " << p[i].getItemPrice() << std::endl;
    }
    std::cout << "Enter product code (0 to exit): ";
    std::cin >> itemCode;

    return itemCode;
}

int searchItem(Item p[], int n, int searchCode)
{

    // Checking the code
    int productIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (p[i].getItemNo() == searchCode)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    Item itemArr[MAX_PRODUCTS];

    std::ifstream infile("ITEMS4437.TXT");
    if (!infile)
    {
        std::cout << "Error opening input file." << std::endl;
        return 1;
    }

    int numProducts = fileToArr(infile, itemArr);

    infile.close();

    int orderNo;
    char orderDate[11];
    int custNo;
    char custName[21];
    char custEmail[21];
    int quantity;
    float totalPrice = 0.0;

    std::cout << "Enter the Customer Number: ";
    std::cin >> custNo;
    std::cout << "Enter the Customer Name: ";
    std::cin >> custName;
    std::cout << "Enter the Customer Email:";
    std::cin >> custEmail;
    std::cout << "Enter the Order Number: ";
    std::cin >> orderNo;
    std::cout << "Enter Order Date: ";
    std::cin >> orderDate;

    Order order(orderNo, orderDate, 0.0, custNo, custName, custEmail, 0, "", 0.0);

    std::ofstream outfile("ORDERS4437.TXT");
    if (!outfile)
    {
        std::cout << "Error opening output file." << std::endl;
        return 1;
    }

    outfile << "Customer No: " << custNo << std::endl;
    outfile << "Customer Name: " << custName << std::endl;
    outfile << "Customer Email: " << custEmail << std::endl;
    outfile << "Order No: " << orderNo << std::endl;
    outfile << "Order Date: " << orderDate << std::endl;
    outfile << std::endl;

    outfile << "Kwdikos\t\t\t\t\tPerigrafi\t\t\t\tPosotita\t\t\t Timi\t\t\tAxia" << std::endl;
    outfile << "==========\t\t=============\t\t============\t\t=======\t\t======" << std::endl;

    int selectedCode;
    do
    {
        selectedCode = itemMenu(itemArr, numProducts);

        int productIndex = searchItem(itemArr, numProducts, selectedCode);

        if (productIndex != -1)
        {
            std::cout << "Enter quantity: ";
            std::cin >> quantity;

            float price = itemArr[productIndex].getItemPrice();
            float amount = price * quantity;
            int shipping = order.shippingCost();

            outfile << std::setw(5) << selectedCode << std::setw(18) << itemArr[productIndex].getItemDesc() << std::setw(14)
                    << quantity << std::setw(14) << price << std::setw(10) << amount << std::endl;

            totalPrice += amount;
            std::cout << ".......Purchase is done,continue you shopping!" << std::endl;
        }
        else
        {
            if (selectedCode != 0)
            {
                std::cout << ".......This Code does not exist!" << std::endl;
            }
            else
            {
                std::cout << ".......Thanks For you purchase!" << std::endl;
            }
        }
    } while (selectedCode != 0);

    outfile << std::setw(60) << "Shipping Cost: " << order.shippingCost() << std::endl;
    outfile << std::setw(60) << "Total amount of buys: " << totalPrice + order.shippingCost() << std::endl;
    outfile.close();

    return 0;
}
