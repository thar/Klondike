#include "StockToWaistCommand.h"

void StockToWaistCommand::execute()
{
    assert(valid_);
    Pile tempPile = stock_.actionPop(3);
    tempPile.turnCardsUp();
    tempPile.reverse();
    movedCards_ = tempPile.size();
    waist_.actionPush(tempPile);
}

void StockToWaistCommand::undo()
{
    Pile tempPile = waist_.actionPop(movedCards_);
    tempPile.turnCardsDown();
    tempPile.reverse();
    stock_.actionPush(tempPile);
}

void StockToWaistCommand::__validate()
{
    valid_ = stock_.getRemainingCards() > 0;
}