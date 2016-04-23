#include "Card.h"

bool Card::isNextValue(const Card& card) const
{
    return value_->isNextValue(*card.value_);
}

bool Card::isPrevValue(const Card& card) const
{
    return value_->isPrevValue(*card.value_);
}

bool Card::isSameValue(const Value& value) const
{
    return *value_ == value;
}

bool Card::isSameSuit(const Card& card) const
{
    return *card.suit_ == *suit_;
}

bool Card::isSameColor(const Card& card) const
{
    return suit_->isSameColor(*card.suit_);
}

bool Card::isFaceUp() const
{
    return faceUp_;
}

void Card::turnCard()
{
    faceUp_ = !faceUp_;
}

std::ostream& operator<<(std::ostream& os, const Card& obj)
{
    os << std::string("[");
    if (obj.faceUp_)
    {
        os << *obj.value_ << std::string(",") << *obj.suit_;
    }
    return os;
}