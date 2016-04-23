#ifndef KLONDIKE_WAIST_H
#define KLONDIKE_WAIST_H


#include "Pile.h"

class Waist
{
public:
    Waist() {};
    void actionPush(Pile pile)
    {
        waistPile_.turnCardsDown();
        waistPile_.appendPile(pile);
    };

    Pile actionPop(unsigned int numberOfCards)
    {
        return waistPile_.popPile(numberOfCards);
    };

    Pile actionPop()
    {
        return waistPile_.popPile(waistPile_.size());
    };
protected:
private:
    Pile waistPile_;

    friend std::ostream& operator<<(std::ostream& os, const Waist& obj);
};


#endif //KLONDIKE_WAIST_H
