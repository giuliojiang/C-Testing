#include "Cd.h"

CD::CD(std::string _title, int _price, int _playTime, int _tracks) :
    Item(_title, _price), playTime(_playTime), tracks(_tracks)
{
}

void CD::calculateTax()
{
    tax = tracks * 5;
}

void CD::print()
{
    calculateTax();
    std::cout << "CD[title='" << title << "',price=" << price << ",playTime=" << playTime << ",tracks=" << tracks << ",taxedPrice=" << price + tax << std::endl;
}