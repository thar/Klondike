#ifndef KLONDIKE_GIVEUPGAMEACTION_H
#define KLONDIKE_GIVEUPGAMEACTION_H

#include "../../utils/MenuEntry.h"
#include "../ConfigurationController.h"

class GiveUpGameAction : public MenuEntry
{
public:
    GiveUpGameAction(controllers::ConfigurationController& configurationController) :
            MenuEntry("Give up game"), configurationController_(configurationController)
    {}
    void doAction() { configurationController_.giveUpGame(); }
    void accept(MenuEntryVisitor &menuEntryVisitor) {}
protected:
private:
    controllers::ConfigurationController& configurationController_;
};


#endif //KLONDIKE_GIVEUPGAMEACTION_H
