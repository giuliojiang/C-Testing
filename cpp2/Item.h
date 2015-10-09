#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item
{
protected:
    std::string title;
    int price;
    int tax;
public:
    Item(std::string _title, int _price);
    virtual void print() {};
    virtual ~Item() {};
    virtual void calculateTax() {};
};

#endif