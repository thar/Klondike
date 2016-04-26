#include "WaistToStockCommand.h"

void WaistToStockCommand::execute()
{
    assert(valid_);
    cardsToMove_ = 0;
    Pile tempPile = origin_.actionPopAll(Waist::pileName);
    for(const auto& card : tempPile)
    {
        if (card.isFaceUp())
        {
            cardsToMove_++;
        }
    }
    tempPile.turnCardsDown();
    tempPile.reverse();
    destiny_.actionPush(tempPile, Stock::pileName);
}

void WaistToStockCommand::undo()
{
    Pile tempPile = destiny_.actionPopAll(Stock::pileName);
    tempPile.turnCardsDown();
    tempPile.reverse();
    Pile faceUpPile = tempPile.popPile(cardsToMove_);
    faceUpPile.turnCardsUp();
    tempPile.appendPile(faceUpPile);
    origin_.actionPush(tempPile, Waist::pileName);
}

void WaistToStockCommand::__validate()
{
    valid_ = origin_.getRemainingCards(Stock::pileName) == 0;
}

std::shared_ptr<KlondikeCommand> WaistToStockCommand::clone()
{
    return std::make_shared<WaistToStockCommand>(*this);
}