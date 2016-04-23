#ifndef KLONDIKE_GAME_H
#define KLONDIKE_GAME_H


#include "Waist.h"
#include "Stock.h"
#include "Foundation.h"
#include "Tableau.h"

class Game
{
public:
protected:
private:
    Waist waist_;
    Stock stock_;
    Foundation foundation_;
    Tableau tableau_;

};


#endif //KLONDIKE_GAME_H
