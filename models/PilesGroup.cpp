#include <iostream>
#include "PilesGroup.h"

PilesGroup::PilesGroup(unsigned int numberOfPiles) : piles_(numberOfPiles)
{}

void PilesGroup::actionPush(Pile &pile, unsigned int pileIndex)
{
    assert(pileIndex <= getNumberOfPiles());
    Pile& destinyPile = getPile(pileIndex);
    destinyPile.appendPile(pile);
}

Pile PilesGroup::actionPop(unsigned int numberOfCards, unsigned int pileIndex)
{
    assert(pileIndex <= getNumberOfPiles());
    Pile& destinyPile = getPile(pileIndex);
    return destinyPile.popPile(numberOfCards);
}

Pile PilesGroup::actionPopAll(unsigned int pileIndex)
{
    assert(pileIndex <= getNumberOfPiles());
    Pile& destinyPile = getPile(pileIndex);
    return destinyPile.popPile(destinyPile.size());
}

Pile& PilesGroup::getPile(unsigned int pileIndex) {
    assert(pileIndex <= getNumberOfPiles());
    return piles_[pileIndex];
}

unsigned int PilesGroup::getRemainingCards(unsigned int pileIndex)
{
    return piles_[pileIndex].size();
}

std::ostream& operator<<(std::ostream& os, const PilesGroup& obj)
{
    for(auto it = obj.piles_.begin(); it != obj.piles_.end() - 1; it++)
    {
        os << *it << std::endl;
    }
    os << obj.piles_.back();
    return os;
}