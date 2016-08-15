#ifndef KLONDIKE_CONSOLEVIEW_H
#define KLONDIKE_CONSOLEVIEW_H


#include "../../View.h"
#include "DeckSelectionView.h"
#include "AutomaticActionListView.h"
#include "../../controllers/local/UserActionListController.h"
#include "../../controllers/local/AutomaticDeckActionListController.h"
#include "../../controllers/local/AutomaticGameActionListController.h"


namespace views
{
    namespace console
    {
        class ConsoleView : public View
        {
        public:
            void interact(controllers::OperationController &operationController) {
                operationController.accept(*this);
            }


            void visit(controllers::local::UserActionListController& controller)
            {
                DeckSelectionView().interact(controller);
            }
            void visit(controllers::local::AutomaticDeckActionListController& controller)
            {
                AutomaticActionListView().interact(controller);
            }
            void visit(controllers::local::AutomaticGameActionListController& controller)
            {
                AutomaticActionListView().interact(controller);
            }

        protected:
        private:
        };
    }
}


#endif //KLONDIKE_CONSOLEVIEW_H
