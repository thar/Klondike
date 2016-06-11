#ifndef KLONDIKE_VALUE_H
#define KLONDIKE_VALUE_H


#include <string>
#include "CardProperty.h"

class Value : public CardProperty
{
public:
    Value(int value, const std::string &propertyString, bool isAce, bool isKing)
            : CardProperty(value, propertyString), isAce_(isAce), isKing_(isKing)
    {}

    bool isNextValue(const Value& value) const
    {
        return (value.getValue() == (getValue() + 1));
    }

    bool isPrevValue(const Value& value) const
    {
        return (value.getValue() == (getValue() - 1));
    }

    bool isAce() const
    {
        return isAce_;
    }

    bool isKing() const
    {
        return isKing_;
    }

protected:
private:
    bool isAce_;
    bool isKing_;
};

#endif //KLONDIKE_VALUE_H
