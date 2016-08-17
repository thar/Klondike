#include <iostream>
#include "Foundation.h"
#include "Localization.h"

Foundation::Foundation(std::set<std::string> suitsNames) : PilesGroup(suitsNames, Localization::getInstance().getValue(localization::FOUNDATION))
{
};
bool Foundation::isCardPushable(Card &card)
{
    return isCardPushable(card.getSuitName(), card);
}
bool Foundation::isCardPushable(const std::string &pileName, Card &card)
{
    bool resultValue = false;
    std::string suitName = card.getSuitName();
    if (suitName == pileName && hasPileName(suitName))
    {
        Pile &destinyPile = getPile(suitName);
        if ((destinyPile.size() == 0 && card.isAce()) ||
            (destinyPile.size() > 0 && destinyPile.back().isPrevValue(card)))
        {
            resultValue = true;
        }
    }
    return resultValue;
}
void Foundation::pushCard(Card &card)
{
    assert(isCardPushable(card.getSuitName(), card));
    getPile(card.getSuitName()).appendCard(card);
}