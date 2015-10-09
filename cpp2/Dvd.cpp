#include "Dvd.h"

// class DVD : public Item
// {
// public:
//     enum Type {PAL, NTSC};
// private:
//     int playTime;
//     Type type;
// public:
//     DVD(std::string _title, int _price, int _playTime, Type _type);
//     void print();
//     void calculateTax();
// }

DVD::DVD(std::string _title, int _price, int _playTime, DVD::DVDFormat _type) :
    Item(_title, _price), playTime(_playTime), type(_type)
{
}

void DVD::calculateTax()
{
    tax = playTime * 2;
}

void DVD::print()
{
    calculateTax();
    std::cout << "DVD[title='" << title << "',price=" << price << ",playTime=" << playTime << ",type=" << getTypeString() << ",taxedPrice=" << price + tax << std::endl;
}

std::string DVD::getTypeString()
{
    if (type == DVD::PAL)
    {
        return std::string("PAL");
    }
    return std::string("NTSC");
}