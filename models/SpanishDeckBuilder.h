#ifndef KLONDIKE_SPANISHDECKFACTORY_H
#define KLONDIKE_SPANISHDECKFACTORY_H

#include "DeckBuilder.h"
#include "SpanishSuit.h"

class SpanishDeckBuilder : public DeckBuilder
{
public:
    std::vector< std::shared_ptr<Value> > createValueContainer()
    {
        //TODO: Take it from file
        std::vector< std::shared_ptr<Value> > valueContainer;
        valueContainer.reserve(10);
        valueContainer.push_back(std::make_shared<Value>(1,"1"));
        valueContainer.push_back(std::make_shared<Value>(2,"2"));
        valueContainer.push_back(std::make_shared<Value>(3,"3"));
        valueContainer.push_back(std::make_shared<Value>(4,"4"));
        valueContainer.push_back(std::make_shared<Value>(5,"5"));
        valueContainer.push_back(std::make_shared<Value>(6,"6"));
        valueContainer.push_back(std::make_shared<Value>(7,"7"));
        valueContainer.push_back(std::make_shared<Value>(8,"Sota"));
        valueContainer.push_back(std::make_shared<Value>(9,"Caballo"));
        valueContainer.push_back(std::make_shared<Value>(10,"Rey"));
        return valueContainer;
    }

    std::vector< std::shared_ptr<Suit> > createSuitContainer()
    {
        //TODO: Take it from file
        std::vector< std::shared_ptr<Suit> > suitContainer;
        suitContainer.reserve(4);
        suitContainer.push_back(std::make_shared<SpanishSuit>(1, "Oros"));
        suitContainer.push_back(std::make_shared<SpanishSuit>(2, "Copas"));
        suitContainer.push_back(std::make_shared<SpanishSuit>(3, "Espadas"));
        suitContainer.push_back(std::make_shared<SpanishSuit>(4, "Bastos"));
        return suitContainer;
    }

protected:
private:
};




#endif //KLONDIKE_SPANISHDECKFACTORY_H
