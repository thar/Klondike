#ifndef KLONDIKE_LOCALPLAYERCONTROLLER_H
#define KLONDIKE_LOCALPLAYERCONTROLLER_H

#include "../PlayerController.h"
#include "../../models/GameDeck.h"
#include "../../models/Game.h"
#include "../NewOrLoadController.h"
#include "../ChooseDeckController.h"
#include "../DeckOptionsVisitor.h"
#include "DeckOption.h"
#include <stack>

namespace controllers
{
    namespace local
    {
        class LocalPlayerController : public PlayerController
        {
        public:
            LocalPlayerController(controllers::GameActionController &gameActionController) : gameActionController_(
                    gameActionController)
            {
                availableDecks_.push_back(
                        std::make_shared<DeckOption>(gameActionController_, "Spanish", "config/decks/spanishDeck.txt"));
                availableDecks_.push_back(
                        std::make_shared<DeckOption>(gameActionController_, "French", "config/decks/frenchDeck.txt"));
            }

            void getActionsMenuEntriesPtr(std::vector<std::shared_ptr<MenuEntry>> *&entriesPtr)
            { entriesPtr = &availableActions_; }

            void getDecksMenuEntriesPtr(std::vector<std::shared_ptr<MenuEntry>> *&entriesPtr)
            { entriesPtr = &availableDecks_; }

            void addGameAction(std::shared_ptr<MenuEntry> gameAction)
            {
                availableActions_.push_back(gameAction);
            }

            std::stack<std::shared_ptr<KlondikeCommand>> &getUndoStack()
            { return undoStack_; }

            std::stack<std::shared_ptr<KlondikeCommand>> &getRedoStack()
            { return redoStack_; }

        protected:
            controllers::GameActionController &gameActionController_;
            std::stack<std::shared_ptr<KlondikeCommand>> undoStack_;
            std::stack<std::shared_ptr<KlondikeCommand>> redoStack_;
            std::vector<std::shared_ptr<MenuEntry>> availableActions_;
            std::vector<std::shared_ptr<MenuEntry>> availableDecks_;

        private:
        };
    }
}


#endif //KLONDIKE_LOCALPLAYERCONTROLLER_H
