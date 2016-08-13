#ifndef KLONDIKE_GAMEACTIONVIEW_H
#define KLONDIKE_GAMEACTIONVIEW_H

#include "PlayerInteractionView.h"
#include "KlondikeCommandGameActionView.h"
#include "../../controllers/local/DeckOption.h"
#include "../../controllers/local/KlondikeCommandGameAction.h"
#include "../../controllers/local/ExitGameAction.h"
#include "../../controllers/local/GiveUpGameAction.h"
#include "../../controllers/local/RedoGameAction.h"
#include "../../controllers/local/UndoGameAction.h"

namespace views
{
    namespace console
    {
        class GameActionView : public PlayerInteractionView
        {
        public:
            GameActionView(Game& game) : game_(game) {}
            std::shared_ptr<MenuEntry> getAutomaticInput(controllers::local::LocalDemoPlayer& player)
            {
                return player.getRandomMove();
            }

            void showMenuHeader()
            {
                std::cout << game_ << std::endl;
            }

            void getMenuEntriesPtr(controllers::local::LocalPlayerController& player)
            {
                player.getActionsMenuEntriesPtr(entries_);
            }

            void visit(KlondikeCommandGameAction &entry)
            {
                entry.init();
                KlondikeCommandGameActionView().interact(entry);
            }

            void visit(UndoGameAction &entry) {}
            void visit(RedoGameAction &entry) {}
            void visit(GiveUpGameAction &entry) {}
            void visit(ExitGameAction &entry) {}
            void visit(DeckOption &entry) {}
        protected:
        private:
            Game& game_;
        };
    }
}


#endif //KLONDIKE_GAMEACTIONVIEW_H
