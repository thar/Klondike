#include "WaistToStockCommand.h"

void WaistToStockCommand::execute()
{
    assert(valid_);
    faceUpCards_ = 0;
    Pile tempPile = waist_.actionPop();
    for(const auto& card : tempPile)
    {
        if (card.isFaceUp())
        {
            faceUpCards_++;
        }
    }
    tempPile.turnCardsDown();
    tempPile.reverse();
    stock_.actionPush(tempPile);
}

void WaistToStockCommand::undo()
{
    Pile tempPile = stock_.actionPop();
    tempPile.turnCardsDown();
    tempPile.reverse();
    Pile faceUpPile = tempPile.popPile(faceUpCards_);
    faceUpPile.turnCardsUp();
    tempPile.appendPile(faceUpPile);
    waist_.actionPush(tempPile);
}

void WaistToStockCommand::__validate()
{
    valid_ = stock_.getRemainingCards() == 0;
}