#ifndef KLONDIKE_FOUNDATION_H
#define KLONDIKE_FOUNDATION_H


#include <memory>
#include "Pile.h"
#include "GameDeck.h"
#include "PilesGroup.h"

class Foundation : public PilesGroup
{
public:
    Foundation(std::set<std::string> suitsNames) : PilesGroup(suitsNames, "palo")
    {
    };

protected:
private:

};


#endif //KLONDIKE_FOUNDATION_H
