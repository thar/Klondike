#include "WaistToFoundationCommand.h"

void WaistToFoundationCommand::__execute()
{
    assert(valid_);
    cardsToMove_ = 1;
    Pile tempPile = origin_.actionPop(cardsToMove_, originPile_);
    destinyPile_ = tempPile.getSuit();
    destiny_.pushCard(tempPile.back());
}

void WaistToFoundationCommand::__undo()
{
    Pile tempPile = destiny_.actionPop(cardsToMove_, destinyPile_);
    origin_.actionPush(tempPile, originPile_);
}

void WaistToFoundationCommand::__validate()
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

std::shared_ptr<KlondikeCommand> WaistToFoundationCommand::clone()
{
    return std::make_shared<WaistToFoundationCommand>(*this);
}