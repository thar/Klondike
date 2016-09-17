#include "Tableau.h"
#include "Localization.h"

Tableau::Tableau(Pile &pile) : PilesGroup({"1", "2", "3", "4", "5", "6", "7"}, Localization::getInstance().getValue(localization::TABLEAU))
{
    pile.shuffle();
    unsigned int i = 1;
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

bool Tableau::isCardPushable(const std::string &pileName, Card &card)
{
    Pile &destinyPile = getPile(pileName);
    if (destinyPile.size() == 0 && card.isKing())
        return true;
    Card &topDestinyCard = destinyPile.back();
    if (card.isNextValue(topDestinyCard) && !card.isSameColor(topDestinyCard))
        return true;
    return false;
}
