#include "StockToWaistCommand.h"

void StockToWaistCommand::execute()
{
    assert(valid_);
    Pile tempPile = origin_.actionPop(3, originPile_);
    tempPile.turnCardsUp();
    tempPile.reverse();
    cardsToMove_ = tempPile.size();
    Pile tempDestinyPileCards = destiny_.actionPop(3, destinyPile_);
    unsigned int reversedDestinyCards = 0;
    for (auto& card : tempDestinyPileCards)
    {
        if (card.isFaceUp())
            reversedDestinyCards++;
    }
    destinyPileCards = tempDestinyPileCards.popPile(reversedDestinyCards);
    tempDestinyPileCards.turnCardsDown();
    destinyPileCards.turnCardsDown();

    destiny_.actionPush(tempDestinyPileCards, Waist::pileName);
    destiny_.actionPush(destinyPileCards, Waist::pileName);
    destiny_.actionPush(tempPile, destinyPile_);
}

void StockToWaistCommand::undo()
{
    Pile tempPile = destiny_.actionPop(cardsToMove_, destinyPile_);
    destiny_.actionPop(destinyPileCards.size(), destinyPile_);
    destinyPileCards.turnCardsUp();
    destiny_.actionPush(destinyPileCards, destinyPile_);
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