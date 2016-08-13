#ifndef KLONDIKE_CONSOLEVIEW_H
#define KLONDIKE_CONSOLEVIEW_H


#include "../../View.h"
#include "PlayerSelectionView.h"
#include "LoadAskView.h"
#include "NewGameView.h"
#include "LoadGameView.h"
#include "DeckSelectionView.h"
#include "StartGameView.h"
#include "GameActionView.h"
#include "SaveGameView.h"
#include "GiveUpGameView.h"
#include "ExitGameView.h"
#include "../../controllers/PlayerSeleccionController.h"
#include "../../controllers/ExitGameController.h"

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

            void visit(controllers::PlayerSeleccionController &playerSelectionController) {
                PlayerSelectionView().interact(playerSelectionController);
            }

            void visit(controllers::NewOrLoadController &newOrLoadController) {
                NewGameView().interact(newOrLoadController);
            }

            void visit(controllers::ChooseDeckController &chooseDeckController) {
                DeckSelectionView().interact(chooseDeckController.getPlayer());
            }

            void visit(controllers::GameActionController &gameActionController) {
                GameActionView gameActionView = GameActionView(gameActionController.getGame());
                gameActionView.interact(*(gameActionController.getPlayerController()));
            }

            void visit(controllers::ExitGameController &exitGameController) {
                ExitGameView().interact(exitGameController);
            };

        protected:
        private:
        };
    }
}


#endif //KLONDIKE_CONSOLEVIEW_H
