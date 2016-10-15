#include "TableauToTableauCommand.h"

void TableauToTableauCommand::__execute()
{
    assert(valid_);
    Pile tempPile = origin_.actionPop(cardsToMove_, originPile_);
    Pile tempLastOriginCard = origin_.actionPop(1, originPile_);
    if (0 != tempLastOriginCard.size() && !tempLastOriginCard.front().isFaceUp())
    {
        tempLastOriginCard.turnCardsUp();
        turnOriginCard_ = true;
    }
    origin_.actionPush(tempLastOriginCard, originPile_);
    destiny_.actionPush(tempPile, destinyPile_);
}

void TableauToTableauCommand::__undo()
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

void TableauToTableauCommand::__validate()
{
    Pile tempPile = origin_.actionPop(cardsToMove_, originPile_);
    if (tempPile.size() == 0)
    {
        valid_ = false;
    }
    else if (destiny_.isCardPushable(destinyPile_, tempPile.front()))
    {
        valid_ = true;
    }
    else
    {
        valid_ = false;
    }
    origin_.actionPush(tempPile, originPile_);
}

std::shared_ptr<KlondikeCommand> TableauToTableauCommand::clone()
{
    return std::make_shared<TableauToTableauCommand>(*this);
}