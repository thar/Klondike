#ifndef KLONDIKE_WAIST_H
#define KLONDIKE_WAIST_H


#include "Pile.h"
#include "PilesGroup.h"

class Waist : public  PilesGroup
{
public:
    Waist() : PilesGroup(pilesSize) {};
    static const unsigned int pileIndex;

protected:
private:
    static const unsigned int pilesSize;

};


#endif //KLONDIKE_WAIST_H
