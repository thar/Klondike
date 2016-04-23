#ifndef KLONDIKE_CARDPROPERTY_H
#define KLONDIKE_CARDPROPERTY_H

#include <string>

class CardProperty
{
public:
    CardProperty(const int& value, const std::string& propertyString) : value_(value), propertyString_(propertyString)
    {}

    int getValue() const
    {
        return value_;
    }

protected:

private:
    int value_;
    std::string propertyString_;

    friend bool operator<(const CardProperty& l, const CardProperty& r);
    friend bool operator==(const CardProperty& l, const CardProperty& r);
    friend std::ostream& operator<<(std::ostream& os, const CardProperty& obj);
};

inline bool operator<(const CardProperty& lhs, const CardProperty& rhs)
{
    return lhs.value_ < rhs.value_;
}

inline bool operator>(const CardProperty& lhs, const CardProperty& rhs)
{
    return rhs < lhs;
}

inline bool operator<=(const CardProperty& lhs, const CardProperty& rhs)
{
    return !(lhs > rhs);
}

inline bool operator>=(const CardProperty& lhs, const CardProperty& rhs)
{
    return !(lhs < rhs);
}

inline bool operator==(const CardProperty& lhs, const CardProperty& rhs)
{
    return lhs.value_ == rhs.value_;
}

inline bool operator!=(const CardProperty& lhs, const CardProperty& rhs)
{
    return !(lhs == rhs);
}

#endif //KLONDIKE_CARDPROPERTY_H
