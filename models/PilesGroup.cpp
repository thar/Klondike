#include <iostream>
#include "PilesGroup.h"

PilesGroup::PilesGroup(std::set<std::string> pilesName, std::string pilesGroupName)
        : pilesGroupName_(pilesGroupName)
{
    for(const auto& name : pilesName)
    {
        pilesMap_[name] = Pile();
    }
}

void PilesGroup::actionPush(Pile &pile, const std::string pileName)
{
    assert(getPilesNames().count(pileName) == 1);
    Pile& destinyPile = getPile(pileName);
    destinyPile.appendPile(pile);
}

Pile PilesGroup::actionPop(unsigned int numberOfCards, std::string pileName)
{
    assert(getPilesNames().count(pileName) == 1);
    Pile& destinyPile = getPile(pileName);
    return destinyPile.popPile(numberOfCards);
}

Pile PilesGroup::actionPopAll(std::string pileName)
{
    assert(getPilesNames().count(pileName) == 1);
    Pile& destinyPile = getPile(pileName);
    return destinyPile.popPile(destinyPile.size());
}

Pile& PilesGroup::getPile(std::string pileName)
{
    assert(getPilesNames().count(pileName) == 1);
    return pilesMap_[pileName];
}

unsigned int PilesGroup::getRemainingCards(std::string pileName)
{
    return pilesMap_[pileName].size();
}

std::ostream& operator<<(std::ostream& os, const PilesGroup& obj)
{
    int i = 0;
    for(auto it = obj.pilesMap_.begin(); it != obj.pilesMap_.end(); it++)
    {
        if(i != 0)
        {
            os << std::endl;
        }
        os << obj.pilesGroupName_ << " " << it->first << " " << it->second;
        i++;
    }
    return os;
}