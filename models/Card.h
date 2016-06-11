#ifndef KLONDIKE_CARD_H
#define KLONDIKE_CARD_H

#include "Value.h"
#include "Suit.h"
#include <vector>
#include <memory>

class DeckBuilder;
class Card
{
public:
    Card(const std::shared_ptr<Value> value, const std::shared_ptr<Suit> suit)
            : value_(value), suit_(suit), faceUp_(false)
    {}

    bool isNextValue(const Card& card) const;
    bool isPrevValue(const Card& card) const;
    bool isSameValue(const Value& value) const;
    bool isSameSuit(const Card& card) const;
    bool isSameColor(const Card& card) const;

    bool isAce() const;

    bool isKing() const;

    const std::string getSuitName() const;
    bool isFaceUp() const;
    void turnCard();

protected:

private:
    std::shared_ptr<Value> value_;
    std::shared_ptr<Suit> suit_;
    bool faceUp_;

    friend std::ostream& operator<<(std::ostream& os, const Card& obj);
};

#endif //KLONDIKE_CARD_H
