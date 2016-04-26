#include "Stock.h"

const std::string Stock::pileName = "";

Stock::Stock(Pile pile) : PilesGroup({Stock::pileName}, "baraja")
{
    actionPush(pile, Stock::pileName);
}