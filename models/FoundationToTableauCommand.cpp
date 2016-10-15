#include "FoundationToTableauCommand.h"

void FoundationToTableauCommand::__execute()
{
    assert(valid_);
    cardsToMove_ = 1;
    Pile tempPile = origin_.actionPop(cardsToMove_, originPile_);
    destiny_.actionPush(tempPile, destinyPile_);
}

void FoundationToTableauCommand::__undo()
{
    Pile tempPile = destiny_.actionPop(cardsToMove_, destinyPile_);
    origin_.actionPush(tempPile, originPile_);
}

void FoundationToTableauCommand::__validate()
{
    cardsToMove_ = 1;
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

std::shared_ptr<KlondikeCommand> FoundationToTableauCommand::clone()
{
    return std::make_shared<FoundationToTableauCommand>(*this);
}