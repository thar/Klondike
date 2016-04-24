#include "Stock.h"

const unsigned int Stock::pileIndex = 0;
const unsigned int Stock::pilesSize = 1;

Stock::Stock(Pile pile) : PilesGroup(Stock::pilesSize)
{
    actionPush(pile, Stock::pileIndex);
}