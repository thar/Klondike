#ifndef KLONDIKE_PILESGROUP_H
#define KLONDIKE_PILESGROUP_H

#include <map>
#include <set>
#include "Pile.h"

class PilesGroup
{
public:
    PilesGroup(std::set<std::string> pilesName, std::string pilesGroupName);
    void actionPush(Pile &pile, const std::string pileName);
    Pile actionPop(unsigned int numberOfCards, std::string pileName);
    Pile actionPopAll(std::string pileName);
    unsigned int getRemainingCards(std::string pileName);

    bool hasPileName(std::string pileName) const;

    virtual bool isCardPushable(const std::string &pileName, Card &card) = 0;

protected:
    Pile& getPile(std::string pileName);
    std::set<std::string> getPilesNames() const
    {
        std::set<std::string> keys;
        for(const auto it : pilesMap_)
        {
            keys.insert(it.first);
        }
        return keys;
    }
private:
    std::map<std::string, Pile> pilesMap_;
    std::string pilesGroupName_;

    friend std::ostream& operator<<(std::ostream& os, const PilesGroup& obj);

};


#endif //KLONDIKE_PILESGROUP_H
