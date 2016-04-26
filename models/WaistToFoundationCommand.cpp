#include "WaistToFoundationCommand.h"

#include "StockToWaistCommand.h"

void WaistToFoundationCommand::execute()
{
    assert(valid_);
    Pile tempPile = origin_.actionPop(1, Waist::pileName);
    tempPile.turnCardsUp();
    cardsToMove_ = tempPile.size();
    //TODO: select proper destiny pile and append the new card
}

void WaistToFoundationCommand::undo()
{
    //TODO: select proper destiny pile and pop the new card
    //origin_.actionPush(tempPile, Waist::pileName);
}

void WaistToFoundationCommand::__validate()
{
    //TODO
    //valid_ = origin_.getRemainingCards(Stock::pileName) > 0;
}

std::shared_ptr<KlondikeCommand> WaistToFoundationCommand::clone()
{
    return std::make_shared<WaistToFoundationCommand>(*this);
}