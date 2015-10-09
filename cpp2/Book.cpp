#include "Book.h"

Book::Book(std::string _title, int _price, int _pages) :
    Item(_title, _price), pages(_pages)
{
}

void Book::calculateTax()
{
    tax = pages * 4 / 10;
}

void Book::print()
{
    calculateTax();
    std::cout << "Book[title='" << title << "',price=" << price << ",pages=" << pages << ",taxedPrice=" << price + tax << std::endl;
}