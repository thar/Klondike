#ifndef KLONDIKE_TABLEAU_H
#define KLONDIKE_TABLEAU_H


#include "Pile.h"
#include "PilesGroup.h"

class Tableau : public PilesGroup
{
public:
    Tableau(Pile& pile);

    bool isCardPushable(const std::string &pileName, Card &card);

protected:
private:

};


#endif //KLONDIKE_TABLEAU_H
