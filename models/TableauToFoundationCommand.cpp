#include "TableauToFoundationCommand.h"

void TableauToFoundationCommand::execute()
{
    assert(valid_);
    cardsToMove_ = 1;
    Pile tempPile = origin_.actionPop(cardsToMove_, originPile_);
    Pile tempLastOriginCard = origin_.actionPop(1, originPile_);
    if (0 != tempLastOriginCard.size() && !tempLastOriginCard.front().isFaceUp())
    {
        tempLastOriginCard.turnCardsUp();
        turnOriginCard_ = true;
    }
    origin_.actionPush(tempLastOriginCard, originPile_);
    destinyPile_ = tempPile.getSuit();
    destiny_.actionPush(tempPile, destinyPile_);
}

void TableauToFoundationCommand::undo()
{
    if (turnOriginCard_)
    {
        Pile tempLastOriginCard = origin_.actionPop(1, originPile_);
        tempLastOriginCard.turnCardsDown();
        origin_.actionPush(tempLastOriginCard, originPile_);
    }
    Pile tempPile = destiny_.actionPop(cardsToMove_, destinyPile_);
    origin_.actionPush(tempPile, originPile_);
}

void TableauToFoundationCommand::__validate()
{
    cardsToMove_ = 1;
    Pile tempPile = origin_.actionPop(cardsToMove_, originPile_);
    if (tempPile.size() == 0)
    {
        valid_ = false;
    }
    else if (destiny_.isCardPushable(tempPile.front()))
    {
        valid_ = true;
    }
    else
    {
        valid_ = false;
    }
    origin_.actionPush(tempPile, originPile_);
}

std::shared_ptr<KlondikeCommand> TableauToFoundationCommand::clone()
{
    return std::make_shared<TableauToFoundationCommand>(*this);
}