#include "Stock.h"

Stock::Stock(Pile pile) : stockPile_(pile) {}

void Stock::actionPush(Pile& pile)
{
    stockPile_.appendPile(pile);
}

Pile Stock::actionPop(unsigned int numberOfCards)
{
    return stockPile_.popPile(numberOfCards);
}

Pile Stock::actionPop()
{
    return stockPile_.popPile(stockPile_.size());
}

unsigned int Stock::getRemainingCards()
{
    return static_cast<unsigned int>(stockPile_.size());
}

std::ostream& operator<<(std::ostream& os, const Stock& obj)
{
    os << obj.stockPile_;
}