#ifndef KLONDIKE_PILE_H
#define KLONDIKE_PILE_H

#include <vector>
#include <algorithm>
#include <assert.h>
#include "Card.h"

typedef std::vector<Card> CardList;
class Pile
{
public:
    typedef CardList::iterator iterator;
    typedef CardList::const_iterator const_iterator;

    Pile() {};

    void shuffle();
    void appendPile(Pile& pile);
    Pile popPile(unsigned int numberOfCards);
    void appendCard(const Card& card);
    Card popCard();
    void turnCardsUp();
    void turnCardsDown();
    void reverse();
    Card& front();
    Card& back();
    Card& getCard(int position);
    unsigned int size() const;

    const std::string getSuit() const;

    iterator begin() { return cards_.begin(); }
    iterator end() { return cards_.end(); }

protected:
private:
    Pile(std::vector<Card> cards) : cards_(cards)
    {}

    CardList cards_;

    friend std::ostream& operator<<(std::ostream& os, const Pile& obj);
};


#endif //KLONDIKE_PILE_H
