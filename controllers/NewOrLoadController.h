#ifndef KLONDIKE_NEWGAMECONTROLLER_H
#define KLONDIKE_NEWGAMECONTROLLER_H

#include "OperationController.h"
#include "ConfigurationController.h"

namespace controllers
{
    class NewOrLoadController : public OperationController
    {
    public:
        NewOrLoadController(ConfigurationController &configurationController)
                : configurationController_(configurationController)
        {
        }

        void accept(OperationControllerVisitor &operationControllerVisitor)
        {
            operationControllerVisitor.visit(*this);
        }

        void setLoadGame()
        {
            configurationController_.setLoadGame();
        }

        void setNewGame()
        {
            configurationController_.setNewGame();
        }

    protected:
    private:
        ConfigurationController& configurationController_;

    };
}


#endif //KLONDIKE_NEWGAMECONTROLLER_H
