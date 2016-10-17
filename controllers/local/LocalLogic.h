#ifndef KLONDIKE_LOCALLOGIC_H
#define KLONDIKE_LOCALLOGIC_H

#include <memory>
#include <iostream>
#include "../GameController.h"
#include "../ActionListController.h"
#include "../AbandonController.h"
#include "../ExitController.h"
#include "DeckControllerBuilder.h"
#include "PlayerChooseControllerBuilder.h"
#include "GameActionsControllerBuilder.h"

#include "../../models/GameDeck.h"
#include "../../models/Game.h"
#include "../../Logic.h"
#include "../ScoreController.h"

namespace controllers
{
    namespace local
    {
        class LocalLogic : public ::Logic, public controllers::GameController
        {
        public:
            enum GameState
            {
                PLAYER_NOT_SELECTED,
                GAME_NOT_STARTED,
                GAME_NEW,
                GAME_LOAD,
                GAME_STARTED,
                GAME_ABANDONED,
                GAME_FINISHED,
                ABRUPT_EXIT,
            };

            LocalLogic();

            std::shared_ptr<controllers::OperationController> getOperationController();

            void setPlayer(PlayerType playerType);
            void newGame();
            void loadGame();
            void setDeck(std::string deckPath);
            void exitGame();
            void abandonGame();
            void restart();
            void setRandomNumberGeneratorSeed(unsigned int seed);
            void save(GameSaver& gameSaver);
            void restore(controllers::GameSaver &gameSaver);

            static void signalHandler (int signum){
                signalHandlerInstance->abandonGame();
            }

        protected:

        private:
            GameState gameState_;
            PlayerType playerType_;
            std::shared_ptr<Game> game_;
            std::string deckPath_;
            unsigned int randomSeed_;
            std::shared_ptr<controllers::ActionListController> gameActionsController_;

            /*
             * The static variable signalHandlerInstance is needed due to the limitations of the signal handling
             * system. It is needed in this software to stop the demo mode.
             * TODO: This stop mode does not work in all consoles, so a better solution should be investigated
             */
            void registerSignalHandler();
            static LocalLogic* signalHandlerInstance;
        };
    }
}


#endif //KLONDIKE_LOCALLOGIC_H
