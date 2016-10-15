#include "DeckControllerBuilder.h"

#include "UserActionListController.h"
#include "AutomaticDeckActionListController.h"
#include "DeckAction.h"
#include "Localization.h"

controllers::local::DeckControllerBuilder::DeckControllerBuilder(controllers::GameController& gameController,
                                                                 controllers::PlayerType player) :
        gameController_(gameController), player_(player)
{
}

std::shared_ptr<controllers::ActionListController> controllers::local::DeckControllerBuilder::getDeckController()
{
    std::shared_ptr<controllers::ActionListController> deckController;
    switch (player_)
    {
        case USER:
            deckController =
                    std::make_shared<controllers::local::UserActionListController>();
            deckController->setHeader(std::make_shared<StringActionListHeader>(
                    Localization::getInstance().getValue(localization::SELECT) +
                            " " + Localization::getInstance().getValue(localization::DECK)));
            break;
        case DEMO:
            deckController = std::make_shared<controllers::local::AutomaticDeckActionListController>();
            break;
        default:
            return nullptr;
    }
    deckController->addAction(std::make_shared<DeckAction>(gameController_, Localization::getInstance().getValue(localization::SPANISH), "config/decks/spanishDeck.txt"));
    deckController->addAction(std::make_shared<DeckAction>(gameController_, Localization::getInstance().getValue(localization::FRENCH), "config/decks/frenchDeck.txt"));
    return deckController;
}