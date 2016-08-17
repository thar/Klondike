#include "Waist.h"
#include "Localization.h"

const std::string Waist::pileName = "";

Waist::Waist() : PilesGroup({Waist::pileName}, Localization::getInstance().getValue(localization::WAIST)) {};
bool Waist::isCardPushable(const std::string &pileName, Card &card)
{
    return true;
}