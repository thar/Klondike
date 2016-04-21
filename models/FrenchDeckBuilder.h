#ifndef KLONDIKE_FRENCHDECKFACTORY_H
#define KLONDIKE_FRENCHDECKFACTORY_H

#include "DeckBuilder.h"
#include "FrenchSuit.h"

class FrenchDeckBuilder : public DeckBuilder
{
public:
    std::vector< std::shared_ptr<Value> > createValueContainer()
    {
        //TODO: Take it from file
        std::vector< std::shared_ptr<Value> > valueContainer;
        valueContainer.reserve(12);
        valueContainer.push_back(std::make_shared<Value>(1,"As"));
        valueContainer.push_back(std::make_shared<Value>(2,"2"));
        valueContainer.push_back(std::make_shared<Value>(3,"3"));
        valueContainer.push_back(std::make_shared<Value>(4,"4"));
        valueContainer.push_back(std::make_shared<Value>(5,"5"));
        valueContainer.push_back(std::make_shared<Value>(6,"6"));
        valueContainer.push_back(std::make_shared<Value>(7,"7"));
        valueContainer.push_back(std::make_shared<Value>(8,"8"));
        valueContainer.push_back(std::make_shared<Value>(9,"9"));
        valueContainer.push_back(std::make_shared<Value>(10,"J"));
        valueContainer.push_back(std::make_shared<Value>(11,"Q"));
        valueContainer.push_back(std::make_shared<Value>(12,"K"));
        return valueContainer;
    }

    std::vector< std::shared_ptr<Suit> > createSuitContainer()
    {
        //TODO: Take it from file
        std::vector< std::shared_ptr<Suit> > suitContainer;
        suitContainer.reserve(4);
        suitContainer.push_back(std::make_shared<FrenchSuit>(1, "Corazones"));
        suitContainer.push_back(std::make_shared<FrenchSuit>(2, "Picas"));
        suitContainer.push_back(std::make_shared<FrenchSuit>(3, "Diamantes"));
        suitContainer.push_back(std::make_shared<FrenchSuit>(4, "Treboles"));
        return suitContainer;
    }

protected:
private:
};


#endif //KLONDIKE_FRENCHDECKFACTORY_H
