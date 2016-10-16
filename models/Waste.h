#ifndef KLONDIKE_WAIST_H
#define KLONDIKE_WAIST_H


#include "Pile.h"
#include "PilesGroup.h"

class Waste : public  PilesGroup
{
public:
    Waste();
    static const std::string pileName;
    bool isCardPushable(const std::string &pileName, Card &card);

protected:
private:

};


#endif //KLONDIKE_WAIST_H
