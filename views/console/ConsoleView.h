#ifndef KLONDIKE_CONSOLEVIEW_H
#define KLONDIKE_CONSOLEVIEW_H


#include "../../View.h"
#include "ActionListView.h"
#include "../../controllers/local/UserActionListController.h"
#include "../../controllers/local/AutomaticDeckActionListController.h"
#include "../../controllers/local/AutomaticGameActionListController.h"
#include "../../controllers/local/LocalScoreController.h"


namespace views
{
    namespace console
    {
        class ConsoleView : public View
        {
        public:
            void interact(controllers::OperationController &operationController);
            void visit(controllers::local::UserActionListController& controller);
            void visit(controllers::local::AutomaticDeckActionListController& controller);
            void visit(controllers::local::AutomaticGameActionListController& controller);
            void visit(controllers::local::LocalScoreController& controller);

        protected:
        private:
        };
    }
}


#endif //KLONDIKE_CONSOLEVIEW_H
