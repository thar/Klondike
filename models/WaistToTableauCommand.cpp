#include "WaistToTableauCommand.h"

void WaistToTableauCommand::__execute()
{
    assert(valid_);
    cardsToMove_ = 1;
    Pile tempPile = origin_.actionPop(cardsToMove_, originPile_);
    destiny_.actionPush(tempPile, destinyPile_);
}

void WaistToTableauCommand::__undo()
{
    Pile tempPile = destiny_.actionPop(cardsToMove_, destinyPile_);
    origin_.actionPush(tempPile, originPile_);
}

void WaistToTableauCommand::__validate()
{
    cardsToMove_ = 1;
    Pile tempPile = origin_.actionPop(cardsToMove_, originPile_);
    if (destiny_.isCardPushable(destinyPile_, tempPile.front()))
    {
        valid_ = true;
    }
    else
    {
        valid_ = false;
    }
    origin_.actionPush(tempPile, originPile_);
}

std::shared_ptr<KlondikeCommand> WaistToTableauCommand::clone()
{
    return std::make_shared<WaistToTableauCommand>(*this);
}