#include "Tableau.h"

Tableau::Tableau(Pile &pile) : PilesGroup({"1", "2", "3", "4", "5", "6", "7"}, "trabajo")
{
    int i=1;
    for(const auto name : getPilesNames())
    {
        Pile tempPile = pile.popPile(i);
        Pile topCard = tempPile.popPile(1);
        topCard.turnCardsUp();
        tempPile.appendPile(topCard);
        actionPush(tempPile, name);
        i++;
    }
}