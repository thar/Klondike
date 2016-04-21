#ifndef KLONDIKE_DECKFACTORY_H
#define KLONDIKE_DECKFACTORY_H


#include <string>
#include <vector>
#include <assert.h>
#include <memory>
#include "Value.h"
#include "Suit.h"
#include "DeckBuilder.h"
#include "Pile.h"

class DeckFactory
{
public:

    static DeckFactory& getInstance()
    {
        static std::shared_ptr<DeckFactory> deckFactory = nullptr;
        if (!deckFactory)
        {
            deckFactory.reset(new DeckFactory());
        }
        return *deckFactory;
    }

    void createDeckContainers(std::string deckFamily)
    {
        auto builder = DeckBuilder::create(deckFamily);
        suits_ = builder->createSuitContainer();
        values_ = builder->createValueContainer();
    }

    bool isKingValue(const Card& card) const
    {
        assert(values_.size() > 0);
        return card.isSameValue(*values_.back());
    }

    bool isAceValue(const Card& card) const
    {
        assert(values_.size() > 0);
        return card.isSameValue(*values_.front());
    }

    /*
    auto getValueIterator() const
    {
        assert(values_.size() > 0);
        return values_.begin();
    };

    auto getSuitIterator() const
    {
        assert(values_.size() > 0);
        return suits_.begin();
    };
    */

    Pile getFullPile() const
    {
        Pile pile;
        for(const auto& value : values_)
        {
            for(const auto& suit : suits_)
            {
                pile.appendCard(Card(value, suit));
            }
        }
        return pile;
    }

protected:
private:
    DeckFactory() {};
    std::vector< std::shared_ptr<Value> > values_;
    std::vector< std::shared_ptr<Suit> > suits_;
};


#endif //KLONDIKE_DECKFACTORY_H
