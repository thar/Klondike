#ifndef KLONDIKE_DECKSELECTIONVIEW_H
#define KLONDIKE_DECKSELECTIONVIEW_H

#include <iostream>
#include "../../controllers/ChooseDeckController.h"
#include "../../controllers/PlayerControllerVisitor.h"
#include "../../controllers/local/LocalUserPlayer.h"
#include "../../controllers/local/LocalDemoPlayer.h"
#include "PlayerInteractionView.h"

namespace views
{
    namespace console
    {
        class DeckSelectionView : public PlayerInteractionView
        {
        public:
            std::shared_ptr<MenuEntry> getAutomaticInput(controllers::local::LocalDemoPlayer& player)
            {
                return player.getRandomDeck();
            }

            void getMenuEntriesPtr(controllers::local::LocalPlayerController& player)
            {
                player.getDecksMenuEntriesPtr(entries_);
            }

            void visit(KlondikeCommandGameAction &entry) {}
            void visit(UndoGameAction &entry) {}
            void visit(RedoGameAction &entry) {}
            void visit(GiveUpGameAction &entry) {}
            void visit(ExitGameAction &entry) {}
            void visit(DeckOption &entry) {}
        protected:
        private:
        };
    }
}

#endif //KLONDIKE_DECKSELECTIONVIEW_H
