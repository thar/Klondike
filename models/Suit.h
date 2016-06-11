#ifndef KLONDIKE_SUIT_H
#define KLONDIKE_SUIT_H

#include <string>
#include <sstream>
#include "CardProperty.h"

class Suit : public CardProperty
{
public:
    Suit(const int& value, const std::string & propertyString) : CardProperty(value, propertyString)
    {}

    bool isSameColor(const Suit& suit) const
    {
        return static_cast<const CardProperty&>(*this) == static_cast<const CardProperty&>(suit);
    }

    const std::string getSuitName() const
    {
        std::ostringstream stream;
        stream << *this;
        return stream.str();
    }

protected:
private:

};

#endif //KLONDIKE_SUIT_H
