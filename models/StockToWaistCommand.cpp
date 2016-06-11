#include "StockToWaistCommand.h"

void StockToWaistCommand::execute()
{
    assert(valid_);
    Pile tempPile = origin_.actionPop(3, originPile_);
    tempPile.turnCardsUp();
    tempPile.reverse();
    cardsToMove_ = tempPile.size();
    Pile waistPile = destiny_.actionPopAll(destinyPile_);
    waistPile.turnCardsDown();
    waistPile.appendPile(tempPile);
    destiny_.actionPush(waistPile, Waist::pileName);
}

void StockToWaistCommand::undo()
{
    Pile tempPile = destiny_.actionPop(cardsToMove_, destinyPile_);
    tempPile.turnCardsDown();
    tempPile.reverse();
    origin_.actionPush(tempPile, originPile_);
}

void StockToWaistCommand::__validate()
{
    valid_ = origin_.getRemainingCards(originPile_) > 0;
}

std::shared_ptr<KlondikeCommand> StockToWaistCommand::clone()
{
    return std::make_shared<StockToWaistCommand>(*this);
}