#ifndef KLONDIKE_STOCK_H
#define KLONDIKE_STOCK_H


#include "Pile.h"

class Stock
{
public:
    Stock(Pile pile);
    void actionPush(Pile& pile);
    Pile actionPop(unsigned int numberOfCards);
    Pile actionPop();
    unsigned int getRemainingCards();

protected:
private:
    Pile stockPile_;

    friend std::ostream& operator<<(std::ostream& os, const Stock& obj);
};


#endif //KLONDIKE_STOCK_H
