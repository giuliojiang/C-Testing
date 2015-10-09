#ifndef BOOK_H
#define BOOK_H

#include "Item.h"

class Book : public Item
{
private:
    int pages;
public:
    Book(std::string _title, int _price, int _pages);
    void print();
    void calculateTax();
};

#endif