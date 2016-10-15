#ifndef KLONDIKE_KLONDIKECOMMANDGAMEACTIONVIEW_H
#define KLONDIKE_KLONDIKECOMMANDGAMEACTIONVIEW_H

#include "../../models/KlondikeCommandVisitor.h"
#include "../../models/FoundationToTableauCommand.h"
#include "../../models/StockToWasteCommand.h"
#include "../../models/TableauToFoundationCommand.h"
#include "../../models/TableauToTableauCommand.h"
#include "../../models/WasteToFoundationCommand.h"
#include "../../models/WasteToStockCommand.h"
#include "../../models/WasteToTableauCommand.h"
#include "../../controllers/local/KlondikeCommandGameAction.h"

namespace views
{
    namespace console
    {
        class KlondikeCommandGameActionView : public KlondikeCommandVisitor
        {
        public:
            void interact(controllers::local::KlondikeCommandGameAction &entry);
            void visit(FoundationToTableauCommand& command);
            void visit(StockToWasteCommand& command);
            void visit(TableauToFoundationCommand& command);
            void visit(TableauToTableauCommand& command);
            void visit(WasteToFoundationCommand& command);
            void visit(WasteToStockCommand& command);
            void visit(WasteToTableauCommand& command);
            unsigned int getUserInput(std::string message);
            std::string getOptionsInput(std::string message, std::set<std::string> options);
        protected:
        private:
        };
    }
}



#endif //KLONDIKE_KLONDIKECOMMANDGAMEACTIONVIEW_H
