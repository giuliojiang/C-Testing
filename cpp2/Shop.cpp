#include "Shop.h"

void Shop::AddBook(const char* pTitle, 
                unsigned int unitPricePence,
                unsigned int noOfPages)
{
    std::shared_ptr<Item> newbook (new Book(std::string(pTitle), unitPricePence, noOfPages));
    list.push_back(newbook);
}

void Shop::AddDVD(const char* pTitle, 
                unsigned int unitPricePence,
                unsigned int runningTimeMins,
                DVD::DVDFormat format)
{
    std::shared_ptr<Item> newdvd (new DVD(std::string(pTitle), unitPricePence, runningTimeMins, format));
    list.push_back(newdvd);
}

void Shop::AddCD(const char* pTitle, 
                unsigned int unitPricePence,
                unsigned int runningTimeMins,
                unsigned int noOfTracks)
{
    std::shared_ptr<Item> newcd (new CD(std::string(pTitle), unitPricePence, runningTimeMins, noOfTracks));
    list.push_back(newcd);
}
    
void Shop::ShowTaxedPrices() const
{
    for (auto i : list)
    {
        i->print();
    }
}