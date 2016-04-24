#ifndef KLONDIKE_PILESGROUP_H
#define KLONDIKE_PILESGROUP_H

#include <vector>
#include "Pile.h"

class PilesGroup
{
public:
    PilesGroup(unsigned int numberOfPiles);
    void actionPush(Pile& pile, unsigned int pileIndex);
    Pile actionPop(unsigned int numberOfCards, unsigned int pileIndex);
    Pile actionPopAll(unsigned int pileIndex);
    unsigned int getRemainingCards(unsigned int pileIndex);
protected:
    Pile& getPile(unsigned int pileIndex);
    unsigned int getNumberOfPiles() const { return static_cast<unsigned int>(piles_.size()); }
private:
    std::vector<Pile> piles_;

    friend std::ostream& operator<<(std::ostream& os, const PilesGroup& obj);

};


#endif //KLONDIKE_PILESGROUP_H
