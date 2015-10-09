#include "Item.h"

Item::Item(std::string _title, int _price) :
    title(_title), 
    price(_price)
{
    tax = 0;
}