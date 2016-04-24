#include "GameDeck.h"
#include <fstream>
#include <sstream>
#include <iostream>

GameDeck::GameDeck(std::string deckFilePath)
{
    values_ = std::vector< std::shared_ptr<Value> >();
    suits_ = std::vector< std::shared_ptr<Suit> >();
    std::ifstream deckFile(deckFilePath);

    bool addToValues = false;
    bool addToSuits = false;
    std::string line;
    while (std::getline(deckFile, line))
    {
        if(line == std::string("VALUES"))
        {
            addToValues = true;
            addToSuits = false;
        }
        else if(line == std::string("SUITS"))
        {
            addToValues = false;
            addToSuits = true;
        }
        else
        {
            std::istringstream iss(line);
            int propertyValue;
            std::string propertyString;
            iss >> propertyValue >> propertyString;
            if(addToValues)
            {
                values_.push_back(std::make_shared<Value>(propertyValue, propertyString));
            }
            else if(addToSuits)
            {
                suits_.push_back(std::make_shared<Suit>(propertyValue, propertyString));
            }
        }
    }
    for(const auto& value : values_)
    {
        for(const auto& suit : suits_)
        {
            deckPile_.appendCard(Card(value, suit));
        }
    }
}

bool GameDeck::isKing(const Card& card) const
{
    assert(values_.size() > 0);
    return card.isSameValue(*values_.back());
}

bool GameDeck::isAce(const Card& card) const
{
    assert(values_.size() > 0);
    return card.isSameValue(*values_.front());
}

Pile GameDeck::getPile() const
{
    return deckPile_;
}

unsigned int GameDeck::getNumberOfSuits() const
{
    return static_cast<unsigned int>(suits_.size());
}