#ifndef KLONDIKE_SPANISHSUIT_H
#define KLONDIKE_SPANISHSUIT_H


#include "Suit.h"

class SpanishSuit : public Suit
{
public:
    SpanishSuit(const int& value, const std::string& propertyString) : Suit(value, propertyString)
    {}

    bool isSameColor(const Suit& suit) const
    {
        return static_cast<const CardProperty&>(*this) == static_cast<const CardProperty&>(suit);
    }

};


#endif //KLONDIKE_SPANISHSUIT_H
