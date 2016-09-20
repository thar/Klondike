#ifndef KLONDIKE_KLONDIKECOMMANDGAMEACTIONVIEW_H
#define KLONDIKE_KLONDIKECOMMANDGAMEACTIONVIEW_H

#include "../../models/KlondikeCommandVisitor.h"
#include "../../models/FoundationToTableauCommand.h"
#include "../../models/StockToWaistCommand.h"
#include "../../models/TableauToFoundationCommand.h"
#include "../../models/TableauToTableauCommand.h"
#include "../../models/WaistToFoundationCommand.h"
#include "../../models/WaistToStockCommand.h"
#include "../../models/WaistToTableauCommand.h"
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
            void visit(StockToWaistCommand& command);
            void visit(TableauToFoundationCommand& command);
            void visit(TableauToTableauCommand& command);
            void visit(WaistToFoundationCommand& command);
            void visit(WaistToStockCommand& command);
            void visit(WaistToTableauCommand& command);
            unsigned int getUserInput(std::string message);
            std::string getOptionsInput(std::string message, std::set<std::string> options);
        protected:
        private:
        };
    }
}



#endif //KLONDIKE_KLONDIKECOMMANDGAMEACTIONVIEW_H
