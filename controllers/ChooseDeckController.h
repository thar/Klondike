#ifndef KLONDIKE_CHOOSEDECKCONTROLLER_H
#define KLONDIKE_CHOOSEDECKCONTROLLER_H

#include "OperationController.h"
#include "PlayerController.h"
#include "../models/Game.h"
#include <memory>

namespace controllers
{
    class ChooseDeckController : public OperationController
    {
    public:
        ChooseDeckController(std::shared_ptr<Game> &game)
                : game_(game)
        {
        }

        void accept(OperationControllerVisitor &operationControllerVisitor)
        {
            operationControllerVisitor.visit(*this);
        }

        void setDeck(std::string deckName)
        {
            game_ = std::make_shared<Game>(deckName);
        }

    protected:
    private:
        std::shared_ptr<Game>& game_;

    };
}

class ChooseDeckController
{

};


#endif //KLONDIKE_CHOOSEDECKCONTROLLER_H
