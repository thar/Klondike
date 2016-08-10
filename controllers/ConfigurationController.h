#ifndef KLONDIKE_CONFIGURATIONCONTROLLER_H
#define KLONDIKE_CONFIGURATIONCONTROLLER_H

#include <string>

namespace controllers
{
    class ConfigurationController
    {
    public:
        virtual void initDemoPlayer(bool isDemoPlayer) = 0;
        virtual void setExitGame() = 0;
        virtual void setContinueGame() = 0;
        virtual void setLoadGame() = 0;
        virtual void setNewGame() = 0;
        virtual void setDeck(std::string deck) = 0;
    };
}
#endif //KLONDIKE_CONFIGURATIONCONTROLLER_H
