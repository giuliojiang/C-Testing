#ifndef Included_Shop_h
#define Included_Shop_h

#include <vector>
#include <memory>

#include "Item.h"
#include "Book.h"
#include "Cd.h"
#include "Dvd.h"

class Shop {
public:
    void AddBook(const char* pTitle, 
                    unsigned int unitPricePence,
                    unsigned int noOfPages);

    void AddDVD(const char* pTitle, 
                    unsigned int unitPricePence,
                    unsigned int runningTimeMins,
                    DVD::DVDFormat format);

    void AddCD(const char* pTitle, 
                    unsigned int unitPricePence,
                    unsigned int runningTimeMins,
                    unsigned int noOfTracks);
	
    void ShowTaxedPrices() const;
private:
    std::vector<std::shared_ptr<Item>> list;
};


#endif /* #ifndef Included_Shop_h */
