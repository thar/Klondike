#ifndef KLONDIKE_STOCK_H
#define KLONDIKE_STOCK_H


#include "Pile.h"
#include "PilesGroup.h"

class Stock : public PilesGroup
{
public:
    Stock(Pile pile);
    static const std::string pileName;

protected:
private:

};


#endif //KLONDIKE_STOCK_H
