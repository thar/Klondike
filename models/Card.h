#ifndef KLONDIKE_CARD_H
#define KLONDIKE_CARD_H

#include "Value.h"
#include "Suit.h"
#include <vector>
#include <memory>

class Card
{
public:
    Card(const std::shared_ptr<Value> value, const std::shared_ptr<Suit> suit)
            : value_(value), suit_(suit), isFaceOver_(false)
    {}

    bool isNextValue(const Card& card) const
    {
        return value_->isNextValue(*card.value_);
    }

    bool isPrevValue(const Card& card) const
    {
        return value_->isPrevValue(*card.value_);
    }

    bool isSameValue(const Value& value) const
    {
        return *value_ == value;
    }

    bool isSameSuit(const Card& card) const
    {
        return *card.suit_ == *suit_;
    }

    bool isSameColor(const Card& card) const
    {
        return suit_->isSameColor(*card.suit_);
    }

    bool isFaceOver() const
    {
        return isFaceOver_;
    }

    void turnFaceOver()
    {
        isFaceOver_ = !isFaceOver_;
    }

protected:

private:
    std::shared_ptr<Value> value_;
    std::shared_ptr<Suit> suit_;
    bool isFaceOver_;

    friend std::ostream& operator<<(std::ostream& os, const Card& obj);
};

#endif //KLONDIKE_CARD_H
