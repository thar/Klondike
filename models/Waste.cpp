#include "Waste.h"
#include "Localization.h"

const std::string Waste::pileName = "";

Waste::Waste() : PilesGroup({Waste::pileName}, Localization::getInstance().getValue(localization::WASTE)) {};
bool Waste::isCardPushable(const std::string &pileName, Card &card)
{
    return true;
}