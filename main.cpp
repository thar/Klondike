#include <iostream>
#include "models/DeckFactory.h"

int main() {
    DeckFactory::getInstance().createDeckContainers("french");
    Pile pile = DeckFactory::getInstance().getFullPile();

    Card kingCard = pile.getTopmostCard();
    Card aceCard = pile.getFirstCard();
    kingCard.turnFaceOver();
    aceCard.turnFaceOver();
    std::cout << kingCard << "] is king? " <<
            (DeckFactory::getInstance().isKingValue(kingCard) ? std::string("yes") : std::string("no")) << std::endl;
    std::cout << aceCard << "] is king? " <<
    (DeckFactory::getInstance().isKingValue(aceCard) ? std::string("yes") : std::string("no")) << std::endl;
    std::cout << kingCard << "] is ace? " <<
    (DeckFactory::getInstance().isAceValue(kingCard) ? std::string("yes") : std::string("no")) << std::endl;
    std::cout << aceCard << "] is ace? " <<
    (DeckFactory::getInstance().isAceValue(aceCard) ? std::string("yes") : std::string("no")) << std::endl;

    pile.shuffle();
    pile.turnUpmostCard();
    std::cout << pile << std::endl;

    DeckFactory::getInstance().createDeckContainers("spanish");
    pile = DeckFactory::getInstance().getFullPile();
    pile.shuffle();
    pile.turnUpmostCard();
    std::cout << pile << std::endl;

    Pile tempPile = pile.popPile(5);
    std::cout << tempPile << std::endl;
    pile.turnUpmostCard();
    std::cout << pile << std::endl;

    pile.appendPile(tempPile);
    std::cout << pile << std::endl;

    return 0;
}