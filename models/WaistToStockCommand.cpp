#include "WaistToStockCommand.h"

void WaistToStockCommand::execute()
{
    assert(valid_);
    cardsToMove_ = 0;
    Pile tempPile = origin_.actionPopAll(Waist::pileIndex);
    for(const auto& card : tempPile)
    {
        if (card.isFaceUp())
        {
            cardsToMove_++;
        }
    }
    tempPile.turnCardsDown();
    tempPile.reverse();
    destiny_.actionPush(tempPile, Stock::pileIndex);
}

void WaistToStockCommand::undo()
{
    Pile tempPile = destiny_.actionPopAll(Stock::pileIndex);
    tempPile.turnCardsDown();
    tempPile.reverse();
    Pile faceUpPile = tempPile.popPile(cardsToMove_);
    faceUpPile.turnCardsUp();
    tempPile.appendPile(faceUpPile);
    origin_.actionPush(tempPile, Waist::pileIndex);
}

void WaistToStockCommand::__validate()
{
    valid_ = origin_.getRemainingCards(Stock::pileIndex) == 0;
}