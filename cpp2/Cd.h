#ifndef CD_H
#define CD_H

#include "Item.h"

class CD : public Item
{
private:
    int playTime;
    int tracks;
public:
    CD(std::string _title, int _price, int _playTime, int _tracks);
    void print();
    void calculateTax();
};

#endif