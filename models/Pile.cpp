#include "Pile.h"

std::ostream& operator<<(std::ostream& os, const Pile& obj)
{
    for (auto& card : obj.cards_)
    {
        os << card;
    }
    os << std::string("]");
    return os;
}
