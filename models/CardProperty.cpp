#include "CardProperty.h"

std::ostream& operator<<(std::ostream& os, const CardProperty& obj)
{
    os << obj.propertyString_;
    return os;
}