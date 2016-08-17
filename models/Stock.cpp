#include "Stock.h"
#include "Localization.h"

const std::string Stock::pileName = "";

Stock::Stock(Pile pile) : PilesGroup({Stock::pileName}, Localization::getInstance().getValue(localization::STOCK))
{
    actionPush(pile, Stock::pileName);
}