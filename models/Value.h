#ifndef KLONDIKE_VALUE_H
#define KLONDIKE_VALUE_H


#include <string>
#include "CardProperty.h"

class Value : public CardProperty
{
public:
    Value(int value, const std::string & propertyString) : CardProperty(value, propertyString)
    {}

    operator CardProperty&()
    {
        return *this;
    }

    bool isNextValue(const Value& value) const
    {
        return (value.getValue() == (getValue() + 1));
    }

    bool isPrevValue(const Value& value) const
    {
        return (value.getValue() == (getValue() - 1));
    }

protected:
private:
};

#endif //KLONDIKE_VALUE_H
