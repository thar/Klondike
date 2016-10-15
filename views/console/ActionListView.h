#ifndef KLONDIKE_ACTIONLISTVIEW_H
#define KLONDIKE_ACTIONLISTVIEW_H

#include <iostream>
#include "../../controllers/ActionListController.h"
#include "../../controllers/local/MenuEntryVisitor.h"
#include "HeaderActionListView.h"

#include "KlondikeCommandGameActionView.h"
#include "../../controllers/local/KlondikeCommandGameAction.h"

namespace views
{
    namespace console
    {
        class ActionListView : public MenuEntryVisitor
        {
        public:
            void interact(controllers::ActionListController &controller);
            void automaticInteract(controllers::ActionListController &controller);

            void visit(controllers::local::KlondikeCommandGameAction &entry)
            {
                entry.init();
                KlondikeCommandGameActionView().interact(entry);
            }
            void visit(controllers::local::UndoGameAction &entry) {}
            void visit(controllers::local::RedoGameAction &entry) {}
            void visit(controllers::local::GiveUpGameAction &entry) {}
            void visit(controllers::local::ExitGameAction &entry) {}
            void visit(controllers::local::DeckAction &entry) {}
            void visit(controllers::local::SaveGameAction &entry);

        protected:
        private:
            void printMenu(controllers::ActionListController &controller);
            std::shared_ptr<MenuEntry> getUserInput(controllers::ActionListController &controller);
        };
    }
}

#endif //KLONDIKE_ACTIONLISTVIEW_H
