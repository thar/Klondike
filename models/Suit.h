#ifndef KLONDIKE_SUIT_H
#define KLONDIKE_SUIT_H

#include <string>
#include "CardProperty.h"

class Suit : public CardProperty
{
public:
    Suit(const int& value, const std::string & propertyString) : CardProperty(value, propertyString)
    {}

    operator CardProperty&()
    {
        return *this;
    }

    virtual bool isSameColor(const Suit& suit) const = 0;

protected:
private:

};

#endif //KLONDIKE_SUIT_H
