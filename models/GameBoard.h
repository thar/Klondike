#ifndef KLONDIKE_GAMEBOARD_H
#define KLONDIKE_GAMEBOARD_H


#include "Pile.h"
#include "Foundation.h"
#include "Tableau.h"
#include "Stock.h"
#include "Waist.h"

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

    Waist &getWaist()
    {
        return waist_;
    }

private:
    Foundation foundation_;
    Tableau tableau_;
    Stock stock_;
    Waist waist_;

    friend std::ostream& operator<<(std::ostream& os, const GameBoard& obj);

};


#endif //KLONDIKE_GAMEBOARD_H
