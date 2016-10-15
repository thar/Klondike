#include "WasteToTableauCommand.h"

void WasteToTableauCommand::__execute()
{
    assert(valid_);
    cardsToMove_ = 1;
    Pile tempPile = origin_.actionPop(cardsToMove_, originPile_);
    destiny_.actionPush(tempPile, destinyPile_);
}

void WasteToTableauCommand::__undo()
{
    Pile tempPile = destiny_.actionPop(cardsToMove_, destinyPile_);
    origin_.actionPush(tempPile, originPile_);
}

void WasteToTableauCommand::__validate()
{
    cardsToMove_ = 1;
    Pile tempPile = origin_.actionPop(cardsToMove_, originPile_);
    if (tempPile.size() > 0 && destiny_.isCardPushable(destinyPile_, tempPile.front()))
    {
        valid_ = true;
    }
    else
    {
        valid_ = false;
    }
    origin_.actionPush(tempPile, originPile_);
}

std::shared_ptr<KlondikeCommand> WasteToTableauCommand::clone()
{
    return std::make_shared<WasteToTableauCommand>(*this);
}