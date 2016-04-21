#ifndef KLONDIKE_FRENCHSUIT_H
#define KLONDIKE_FRENCHSUIT_H


#include "Suit.h"

class FrenchSuit : public Suit
{
public:
    FrenchSuit(const int& value, const std::string& propertyString) : Suit(value, propertyString)
    {}

    bool isSameColor(const Suit& suit) const
    {
        return static_cast<const CardProperty&>(*this).isPair() == static_cast<const CardProperty&>(suit).isPair();
    }

};


#endif //KLONDIKE_FRENCHSUIT_H
