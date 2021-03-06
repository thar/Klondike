#ifndef KLONDIKE_GAMEDECK_H
#define KLONDIKE_GAMEDECK_H


#include <string>
#include "Pile.h"
#include <set>

class GameDeck
{
public:
    GameDeck(const std::string deckFilePath);
    std::set<std::string> getSuitsNames() const;
    Pile getPile() const;

protected:
private:
    Pile deckPile_;
    std::vector< std::shared_ptr<Value> > values_;
    std::vector< std::shared_ptr<Suit> > suits_;

};


#endif //KLONDIKE_GAMEDECK_H
