#include "DeckControllerBuilder.h"

#include "UserActionListController.h"
#include "AutomaticDeckActionListController.h"
#include "DeckAction.h"

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
                    std::make_shared<controllers::local::UserActionListController>(std::make_shared<StringActionListHeader>("Select Deck"));
            break;
        case DEMO:
            deckController = std::make_shared<controllers::local::AutomaticDeckActionListController>();
            break;
        default:
            return nullptr;
    }
    deckController->addAction(std::make_shared<DeckAction>(gameController_, "Spanish", "decks/spanishDeck.txt"));
    deckController->addAction(std::make_shared<DeckAction>(gameController_, "French", "decks/frenchDeck.txt"));
    return deckController;
}