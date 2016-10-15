#ifndef KLONDIKE_AUTOMATICGAMEACTIONLISTCONTROLLER_H
#define KLONDIKE_AUTOMATICGAMEACTIONLISTCONTROLLER_H

#include "GameActionListHeader.h"
#include "LocalActionListController.h"
#include "MenuEntryVisitor.h"
#include "KlondikeCommandGameAction.h"

namespace controllers
{
    namespace local
    {
        class AutomaticGameActionListController : public LocalActionListController, MenuEntryVisitor, KlondikeCommandVisitor
        {
        public:
            AutomaticGameActionListController(Game& game);
            void accept(controllers::OperationControllerVisitor& visitor);
            std::shared_ptr<MenuEntry> getAutomaticAction();

            void visit(KlondikeCommandGameAction &entry)
            {
                entry.init();
                entry.accept(static_cast<KlondikeCommandVisitor&>(*this));
            }
            void randomFillCommand(KlondikeCommand& command);
            void visit(UndoGameAction &entry) {}
            void visit(RedoGameAction &entry) {}
            void visit(GiveUpGameAction &entry) {}
            void visit(ExitGameAction &entry) {}
            void visit(DeckAction &entry) {}
            void visit(SaveGameAction &entry) {}

            void visit(FoundationToTableauCommand& command);
            void visit(StockToWasteCommand& command);
            void visit(TableauToFoundationCommand& command);
            void visit(TableauToTableauCommand& command);
            void visit(WasteToFoundationCommand& command);
            void visit(WasteToStockCommand& command);
            void visit(WasteToTableauCommand& command);
        protected:
        private:
            Game& game_;
        };
    }
}


#endif //KLONDIKE_AUTOMATICGAMEACTIONLISTCONTROLLER_H
