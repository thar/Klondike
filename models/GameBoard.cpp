#include "GameBoard.h"
#include <iostream>

GameBoard::GameBoard(std::set<std::string> suitsNames, Pile gamePile) :
        foundation_(suitsNames), tableau_(gamePile), stock_(gamePile)
{ }

std::ostream& operator<<(std::ostream& os, const GameBoard& obj)
{
    os << "=======================================" << std::endl;
    os << obj.stock_ << std::endl;
    os << obj.waist_ << std::endl;
    os << obj.foundation_ << std::endl;
    os << obj.tableau_ << std::endl;
    os << "=======================================";
    return os;
}