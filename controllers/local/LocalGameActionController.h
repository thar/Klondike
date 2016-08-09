#ifndef KLONDIKE_LOCALGAMEACTIONCONTROLLER_H
#define KLONDIKE_LOCALGAMEACTIONCONTROLLER_H

#include "../GameActionController.h"
#include "../PlayerController.h"

namespace controllers
{
    namespace local
    {
        class LocalGameActionController : public GameActionController
        {
        public:
            LocalGameActionController(PlayerController &playerController)
                    : playerController_(playerController)
            {
            }
            void accept(OperationControllerVisitor& operationControllerVisitor)
            {
                operationControllerVisitor.visit(*this);
            }

            void giveUpGame()
            {
                playerController_.giveUpGame();
            }
            void undoMovement()
            {
                playerController_.undoMovement();
            }
            void redoMovement()
            {
                playerController_.redoMovement();
            }
            void saveGame()
            {
                playerController_.saveGame();
            }

        protected:
        private:
            PlayerController& playerController_;
        };
    }
}


#endif //KLONDIKE_LOCALGAMEACTIONCONTROLLER_H
