#include "TableauToFoundationCommand.h"

void TableauToFoundationCommand::execute()
{
    assert(valid_);
    Pile tempPile = origin_.actionPop(cardsToMove_, originPile_);
    destinyPile_ = tempPile.getSuit();
    destiny_.pushCard(tempPile.back());
}

void TableauToFoundationCommand::undo()
{
    Pile tempPile = destiny_.actionPop(cardsToMove_, destinyPile_);
    origin_.actionPush(tempPile, originPile_);
}

void TableauToFoundationCommand::__validate()
{
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