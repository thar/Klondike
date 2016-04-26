#include "StockToWaistCommand.h"

void StockToWaistCommand::execute()
{
    assert(valid_);
    Pile tempPile = origin_.actionPop(3, Stock::pileName);
    tempPile.turnCardsUp();
    tempPile.reverse();
    cardsToMove_ = tempPile.size();
    Pile waistPile = destiny_.actionPopAll(Waist::pileName);
    waistPile.turnCardsDown();
    waistPile.appendPile(tempPile);
    destiny_.actionPush(waistPile, Waist::pileName);
}

void StockToWaistCommand::undo()
{
    Pile tempPile = destiny_.actionPop(cardsToMove_, Waist::pileName);
    tempPile.turnCardsDown();
    tempPile.reverse();
    origin_.actionPush(tempPile, Stock::pileName);
}

void StockToWaistCommand::__validate()
{
    valid_ = origin_.getRemainingCards(Stock::pileName) > 0;
}

std::shared_ptr<KlondikeCommand> StockToWaistCommand::clone()
{
    return std::make_shared<StockToWaistCommand>(*this);
}