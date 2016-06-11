#include "GameDeck.h"
#include <fstream>
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
            std::string isAceString;
            std::string isKingString;
            iss >> propertyValue >> propertyString >> isAceString >> isKingString;
            if(addToValues)
            {
                values_.push_back(std::make_shared<Value>(propertyValue, propertyString, isAceString == "yes",
                                                          isKingString == "yes"));
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

Pile GameDeck::getPile() const
{
    return deckPile_;
}

std::set<std::string> GameDeck::getSuitsNames() const
{
    std::set<std::string> suitsNames;
    for (auto&& it : suits_)
    {
        std::ostringstream stream;
        stream << *it;
        suitsNames.insert(stream.str());
    }
    return suitsNames;
}