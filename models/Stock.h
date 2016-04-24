#ifndef KLONDIKE_STOCK_H
#define KLONDIKE_STOCK_H


#include "Pile.h"
#include "PilesGroup.h"

class Stock : public PilesGroup
{
public:
    Stock(Pile pile);
    static const unsigned int pileIndex;

protected:
private:
    static const unsigned int pilesSize;

};


#endif //KLONDIKE_STOCK_H
