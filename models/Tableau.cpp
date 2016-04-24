#include "Tableau.h"

Tableau::Tableau(Pile &pile) : PilesGroup(7)
{
    for(unsigned int i = 0; i < getNumberOfPiles(); i++)
    {
        Pile tempPile = pile.popPile(i+1);
        Pile topCard = tempPile.popPile(1);
        topCard.turnCardsUp();
        tempPile.appendPile(topCard);
        actionPush(tempPile, i);
    }
}