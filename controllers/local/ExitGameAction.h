#ifndef KLONDIKE_EXITGAMEACTION_H
#define KLONDIKE_EXITGAMEACTION_H

#include "../../utils/MenuEntry.h"
#include "../ConfigurationController.h"

class ExitGameAction : public MenuEntry
{
public:
    ExitGameAction(controllers::ConfigurationController& configurationController) :
            MenuEntry("Exit game"), configurationController_(configurationController)
    {}
    void doAction() { configurationController_.setExitGame(); }
    void accept(MenuEntryVisitor &menuEntryVisitor) {}
protected:
private:
    controllers::ConfigurationController& configurationController_;
};

#endif //KLONDIKE_EXITGAMEACTION_H
