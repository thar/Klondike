#ifndef KLONDIKE_FOUNDATION_H
#define KLONDIKE_FOUNDATION_H


#include <memory>
#include "Pile.h"
#include "GameDeck.h"
#include "PilesGroup.h"

class Foundation : public PilesGroup
{
public:
    Foundation(std::set<std::string> suitsNames) : PilesGroup(suitsNames, "palo")
    {
    };

    bool isCardPushable(Card &card)
    {
        return isCardPushable(card.getSuitName(), card);
    }

    bool isCardPushable(const std::string &pileName, Card &card);

    void pushCard(Card &card);

protected:
private:

};


#endif //KLONDIKE_FOUNDATION_H
