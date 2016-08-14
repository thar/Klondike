#ifndef KLONDIKE_GIVEUPGAMEACTION_H
#define KLONDIKE_GIVEUPGAMEACTION_H

#include "../../utils/MenuEntry.h"
#include "../GameController.h.h"

class GiveUpGameAction : public MenuEntry
{
public:
    GiveUpGameAction(controllers::GameController& controller) :
            MenuEntry("Give up game"), controller_(controller)
    {}
    void doAction() { controller_.abandonGame(); }
    void accept(MenuEntryVisitor &menuEntryVisitor) {}
protected:
private:
    controllers::GameController& controller_;
};


#endif //KLONDIKE_GIVEUPGAMEACTION_H
