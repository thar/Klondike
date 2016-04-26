#ifndef KLONDIKE_KLONDIKECOMMANDSHOPBUILDER_H
#define KLONDIKE_KLONDIKECOMMANDSHOPBUILDER_H

#include "GameBoard.h"
#include "KlondikeCommandShop.h"

class KlondikeCommandShopBuilder
{
public:
    static KlondikeCommandShop createCommandShop(GameBoard& board, int& score);
protected:
private:
};


#endif //KLONDIKE_KLONDIKECOMMANDSHOPBUILDER_H
