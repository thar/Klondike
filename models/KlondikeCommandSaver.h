
#ifndef KLONDIKE_KLONDIKECOMMANDSAVER_H
#define KLONDIKE_KLONDIKECOMMANDSAVER_H


#include <string>

class KlondikeCommandSaver
{
public:
    virtual void addOrigin(std::string origin) = 0;
    virtual void addDestiny(std::string destiny) = 0;
    virtual void addNumberOfCards(unsigned int numberOfCards) = 0;
};


#endif //KLONDIKE_KLONDIKECOMMANDSAVER_H
