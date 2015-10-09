#ifndef DVD_H
#define DVD_H

#include "Item.h"

class DVD : public Item
{
public:
    enum DVDFormat {PAL, NTSC};
private:
    int playTime;
    DVDFormat type;
    std::string getTypeString();
public:
    DVD(std::string _title, int _price, int _playTime, DVDFormat _type);
    void print();
    void calculateTax();
};


#endif