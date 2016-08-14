#ifndef KLONDIKE_EXITGAMEACTION_H
#define KLONDIKE_EXITGAMEACTION_H

#include "../../utils/MenuEntry.h"
#include "../GameController.h"

class ExitGameAction : public MenuEntry
{
public:
    ExitGameAction(controllers::GameController& controller) :
            MenuEntry("Exit game"), controller_(controller)
    {}
    void doAction() { controller_.exitGame(); }
    void accept(MenuEntryVisitor &menuEntryVisitor) {}
protected:
private:
    controllers::GameController& controller_;
};

#endif //KLONDIKE_EXITGAMEACTION_H
