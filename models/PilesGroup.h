#ifndef KLONDIKE_PILESGROUP_H
#define KLONDIKE_PILESGROUP_H

#include <vector>
#include "Pile.h"

class PilesGroup
{
public:
    virtual Pile& getPile(int pileIndex) = 0;
protected:
private:
    std::vector<Pile> piles_;
};


#endif //KLONDIKE_PILESGROUP_H
