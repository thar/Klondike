#include "DeckAction.h"

controllers::local::DeckAction::DeckAction(controllers::GameController& gameController,
                                           std::string deckName, std::string deckPath) :
        MenuEntry(deckName), deckPath_(deckPath), gameController_(gameController)
{}

void controllers::local::DeckAction::doAction()
{
    gameController_.setDeck(deckPath_);
}

void controllers::local::DeckAction::accept(MenuEntryVisitor &menuEntryVisitor)
{}