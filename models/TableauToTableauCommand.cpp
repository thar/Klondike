#include "TableauToTableauCommand.h"

void TableauToTableauCommand::execute()
{
    assert(valid_);
    Pile tempPile = origin_.actionPop(cardsToMove_, originPile_);
    destiny_.actionPush(tempPile, destinyPile_);
}

void TableauToTableauCommand::undo()
{
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