#include "Card.h"

std::ostream& operator<<(std::ostream& os, const Card& obj)
{
    os << std::string("[");
    if (obj.isFaceOver_)
    {
        os << *obj.value_ << std::string(",") << *obj.suit_;
    }
    return os;
}