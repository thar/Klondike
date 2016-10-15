#ifndef KLONDIKE_LOCALLOGIC_H
#define KLONDIKE_LOCALLOGIC_H

#include <memory>
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
                GAME_FINISHED
            };

            LocalLogic();

            std::shared_ptr<controllers::OperationController> getOperationController();

            void setPlayer(PlayerType playerType);
            void newGame();
            void loadGame();
            void setDeck(std::string deckPath);
            void exitGame();
            void abandonGame();
            void setRandomNumberGeneratorSeed(unsigned int seed);
            void save(GameSaver& gameSaver);
            void restore(controllers::GameSaver &gameSaver);

        protected:

        private:
            GameState gameState_;
            PlayerType playerType_;
            std::shared_ptr<controllers::ActionListController> playerChooseController_;
            std::shared_ptr<controllers::ActionListController> deckController_;
            std::shared_ptr<controllers::ActionListController> gameActionsController_;
            std::shared_ptr<controllers::ActionListController> loadGameController_;
            std::shared_ptr<controllers::ActionListController> startGameController_;
            std::shared_ptr<controllers::AbandonController> abandonController_;
            //std::shared_ptr<controllers::ExitController> exitController_;
            std::shared_ptr<controllers::ActionListController> exitController_;
            std::shared_ptr<Game> game_;
            bool abruptExit_;
            std::string deckPath_;
            unsigned int randomSeed_;
        };
    }
}


#endif //KLONDIKE_LOCALLOGIC_H
