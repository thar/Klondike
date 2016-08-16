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

            void visit(KlondikeCommandGameAction &entry)
            {
                entry.init();
                KlondikeCommandGameActionView().interact(entry);
            }
            void visit(UndoGameAction &entry) {}
            void visit(RedoGameAction &entry) {}
            void visit(GiveUpGameAction &entry) {}
            void visit(ExitGameAction &entry) {}
            void visit(DeckAction &entry) {}

        protected:
        private:
            void printMenu(controllers::ActionListController &controller);
            std::shared_ptr<MenuEntry> getUserInput(controllers::ActionListController &controller);
        };
    }
}

#endif //KLONDIKE_ACTIONLISTVIEW_H
