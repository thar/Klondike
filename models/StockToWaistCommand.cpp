#include "StockToWaistCommand.h"

void StockToWaistCommand::execute()
{
    assert(valid_);
    Pile tempPile = origin_.actionPop(3, Stock::pileIndex);
    tempPile.turnCardsUp();
    tempPile.reverse();
    cardsToMove_ = tempPile.size();
    Pile waistPile = destiny_.actionPopAll(Waist::pileIndex);
    waistPile.turnCardsDown();
    waistPile.appendPile(tempPile);
    destiny_.actionPush(waistPile, Waist::pileIndex);
}

void StockToWaistCommand::undo()
{
    Pile tempPile = destiny_.actionPop(cardsToMove_, Waist::pileIndex);
    tempPile.turnCardsDown();
    tempPile.reverse();
    origin_.actionPush(tempPile, Stock::pileIndex);
}

void StockToWaistCommand::__validate()
{
    valid_ = origin_.getRemainingCards(Stock::pileIndex) > 0;
}