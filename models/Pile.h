#ifndef KLONDIKE_PILE_H
#define KLONDIKE_PILE_H


#include <vector>
#include <algorithm>
#include <assert.h>
#include "Card.h"

class Pile
{
public:
    Pile() {};

    void shuffle()
    {
        std::srand(time(0));
        std::random_shuffle(std::begin(cards_), std::end(cards_));
    }

    void appendPile(Pile& pile)
    {
        cards_.insert(std::end(cards_), std::begin(pile.cards_), std::end(pile.cards_));
    }

    Pile popPile(int numberOfCards)
    {
        assert(cards_.size() >= numberOfCards);
        Pile pile(std::vector<Card>(std::end(cards_) - numberOfCards, std::end(cards_)));
        cards_.erase(std::end(cards_) - numberOfCards, std::end(cards_));
        return  pile;
    }

    void appendCard(const Card& card)
    {
        cards_.push_back(card);
    }

    Card popCard()
    {
        assert(cards_.size() > 0);
        Card lastCard = cards_.back();
        cards_.pop_back();
        return lastCard;
    }

    Card& getTopmostCard()
    {
        return cards_.back();
    }

    Card& getFirstCard()
    {
        return cards_.front();
    }

    void turnUpmostCard()
    {
        cards_.back().turnFaceOver();
    }

protected:
private:
    Pile(std::vector<Card> cards) : cards_(cards)
    {}

    std::vector<Card> cards_;

    friend std::ostream& operator<<(std::ostream& os, const Pile& obj);
};


#endif //KLONDIKE_PILE_H
