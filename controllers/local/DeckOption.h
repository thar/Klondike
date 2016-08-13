#ifndef KLONDIKE_DECKOPTION_H
#define KLONDIKE_DECKOPTION_H

#include "../../utils/MenuEntry.h"
#include "../DeckOptionsVisitor.h"
#include "../GameActionController.h"

class DeckOption : public MenuEntry
{
public:
    DeckOption(controllers::GameActionController& gameActionController, std::string deckName, std::string deckPath) :
            MenuEntry(deckName), deckPath_(deckPath), gameActionController_(gameActionController)
    {}
    void doAction() { gameActionController_.newGame(deckPath_); }
    void accept(MenuEntryVisitor &menuEntryVisitor) {}
protected:
private:
    std::string deckPath_;
    controllers::GameActionController& gameActionController_;
};


#endif //KLONDIKE_DECKOPTION_H
