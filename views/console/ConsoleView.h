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
                DeckSelectionView().interact(chooseDeckController);
            }

            void visit(controllers::GameActionController &gameActionController) {
                GameActionView().interact(gameActionController);
            }

            /*

            void visit(controllers::local::LocalLoadGameController &localLoadGameController) {
                loadGameView_.interact(localLoadGameController);
            };

            void visit(controllers::local::LocalDeckSelectionController &localDeckSelectionController) {
                deckSelectionView_.interact(localDeckSelectionController);
            };

            void visit(controllers::local::LocalStartGameController &localStartGameController) {
                startGameView_.interact(localStartGameController);
            };

            void visit(controllers::local::LocalSaveGameController &localSaveGameController) {
                saveGameView_.interact(localSaveGameController);
            };

            void visit(controllers::local::LocalGiveUpGameController &localGiveUpGameController) {
                giveUpGameView_.interact(localGiveUpGameController);
            };
            */

            void visit(controllers::ExitGameController &exitGameController) {
                ExitGameView().interact(exitGameController);
            };

        protected:
        private:
            /*
            PlayerSelectionView playerSelectionView_;
            LoadAskView loadAskView_;
            NewGameView newGameView_;
            LoadGameView loadGameView_;
            DeckSelectionView deckSelectionView_;
            StartGameView startGameView_;
            GameActionView gameActionView_;
            SaveGameView saveGameView_;
            GiveUpGameView giveUpGameView_;
            ExitGameView exitGameView_;
            */

        };
    }
}


#endif //KLONDIKE_CONSOLEVIEW_H
