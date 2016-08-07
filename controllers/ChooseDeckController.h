#ifndef KLONDIKE_CHOOSEDECKCONTROLLER_H
#define KLONDIKE_CHOOSEDECKCONTROLLER_H

#include "OperationController.h"
#include "PlayerController.h"

namespace controllers
{
    class ChooseDeckController : public OperationController
    {
    public:
        ChooseDeckController(PlayerController &playerController)
                : playerController_(playerController)
        {
        }

        void accept(OperationControllerVisitor &operationControllerVisitor)
        {
            operationControllerVisitor.visit(*this);
        }

        void setDeck(std::string deckName)
        {
            playerController_.setDeck(deckName);
        }

    protected:
    private:
        PlayerController& playerController_;

    };
}

class ChooseDeckController
{

};


#endif //KLONDIKE_CHOOSEDECKCONTROLLER_H
