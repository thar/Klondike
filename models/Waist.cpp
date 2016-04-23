#include "Waist.h"

std::ostream& operator<<(std::ostream& os, const Waist& obj)
{
    os << obj.waistPile_;
}