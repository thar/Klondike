#include "Pile.h"

void Pile::shuffle()
{
    std::random_shuffle(std::begin(cards_), std::end(cards_));
}

void Pile::appendPile(Pile& pile)
{
    cards_.insert(std::end(cards_), std::begin(pile.cards_), std::end(pile.cards_));
}

Pile Pile::popPile(unsigned int numberOfCards)
{
    auto numberOfCardsToRemove = std::min(static_cast<unsigned int>(cards_.size()), numberOfCards);
    Pile pile(std::vector<Card>(std::end(cards_) - numberOfCardsToRemove, std::end(cards_)));
    cards_.erase(std::end(cards_) - numberOfCardsToRemove, std::end(cards_));
    return  pile;
}

void Pile::appendCard(const Card& card)
{
    cards_.push_back(card);
}

Card Pile::popCard()
{
    assert(cards_.size() > 0);
    Card lastCard = cards_.back();
    cards_.pop_back();
    return lastCard;
}

void Pile::turnCardsUp()
{
    for(auto& card : cards_)
    {
        if (!card.isFaceUp())
        {
            card.turnCard();
        }
    }
}

void Pile::turnCardsDown()
{
    for(auto& card : cards_)
    {
        if (card.isFaceUp())
        {
            card.turnCard();
        }
    }
}

unsigned int Pile::size() const
{
    return static_cast<unsigned int>(cards_.size());
}

const std::string Pile::getSuit() const
{
    auto oneCard = cards_.back();
    bool sameSuit = true;
    for (auto &&card : cards_)
    {
        if (!oneCard.isSameSuit(card))
        {
            sameSuit = false;
        }
    }
    if (sameSuit)
    {
        return oneCard.getSuitName();
    }
    return "";
}

void Pile::reverse()
{
    std::reverse(cards_.begin(),cards_.end());
}

Card& Pile::front()
{
    return cards_.front();
}

Card& Pile::back()
{
    return cards_.back();
}

Card &Pile::getCard(int position)
{
    if (position >= 0)
    {
        assert(position < cards_.size());
        return cards_[position];
    }
    else
    {
        assert(-position <= cards_.size());
        return cards_[cards_.size() + position];
    }
}

std::ostream& operator<<(std::ostream& os, const Pile& obj)
{
    for (auto& card : obj.cards_)
    {
        os << card;
    }
    if (obj.size())
    {
        os << std::string("]");
    }
    else
    {
        os << std::string("X");
    }
    return os;
}
