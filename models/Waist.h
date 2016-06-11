#ifndef KLONDIKE_WAIST_H
#define KLONDIKE_WAIST_H


#include "Pile.h"
#include "PilesGroup.h"

class Waist : public  PilesGroup
{
public:
    Waist() : PilesGroup({Waist::pileName}, "descarte") {};
    static const std::string pileName;

    bool isCardPushable(const std::string &pileName, Card &card)
    { return true; }

protected:
private:
    static const unsigned int pilesSize;

};


#endif //KLONDIKE_WAIST_H
