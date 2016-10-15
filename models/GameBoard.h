#ifndef KLONDIKE_GAMEBOARD_H
#define KLONDIKE_GAMEBOARD_H


#include "Pile.h"
#include "Foundation.h"
#include "Tableau.h"
#include "Stock.h"
#include "Waste.h"

class GameBoard
{
public:
    GameBoard(std::set<std::string> suitsNames, Pile gamePile);

protected:
private:
public:
    Foundation &getFoundation()
    {
        return foundation_;
    }

    Tableau &getTableau()
    {
        return tableau_;
    }

    Stock &getStock()
    {
        return stock_;
    }

    Waste &getWaist()
    {
        return waist_;
    }

    bool isGameFinished()
    {
        return tableau_.getNumberOfCardsInGroup() == 0 &&
                stock_.getNumberOfCardsInGroup() == 0 &&
                waist_.getNumberOfCardsInGroup() == 0;
    }

private:
    Foundation foundation_;
    Tableau tableau_;
    Stock stock_;
    Waste waist_;

    friend std::ostream& operator<<(std::ostream& os, const GameBoard& obj);

};


#endif //KLONDIKE_GAMEBOARD_H
