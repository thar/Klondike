#include "WaistToStockCommand.h"

void WaistToStockCommand::execute()
{
    assert(valid_);
    cardsToMove_ = 0;
    Pile tempPile = origin_.actionPopAll(originPile_);
    for(const auto& card : tempPile)
    {
        if (card.isFaceUp())
        {
            cardsToMove_++;
        }
    }
    tempPile.turnCardsDown();
    tempPile.reverse();
    destiny_.actionPush(tempPile, destinyPile_);
}

void WaistToStockCommand::undo()
{
    Pile tempPile = destiny_.actionPopAll(destinyPile_);
    tempPile.turnCardsDown();
    tempPile.reverse();
    Pile faceUpPile = tempPile.popPile(cardsToMove_);
    faceUpPile.turnCardsUp();
    tempPile.appendPile(faceUpPile);
    origin_.actionPush(tempPile, originPile_);
}

void WaistToStockCommand::__validate()
{
    valid_ = origin_.getRemainingCards(destinyPile_) == 0;
}

std::shared_ptr<KlondikeCommand> WaistToStockCommand::clone()
{
    return std::make_shared<WaistToStockCommand>(*this);
}