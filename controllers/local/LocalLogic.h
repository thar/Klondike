#ifndef KLONDIKE_LOCALLOGIC_H
#define KLONDIKE_LOCALLOGIC_H

#include <memory>
#include "../../models/GameDeck.h"
#include "../../models/Game.h"
#include "../../Logic.h"
#include "LocalDemoPlayer.h"
#include "LocalUserPlayer.h"
#include "../PlayerController.h"
#include "../ConfigurationController.h"
#include "LocalOperationController.h"
#include "LocalPlayerSelectionController.h"
#include "LocalExitGameController.h"

enum LogicState
{
    CHOOSE_ACTION,
    EXEC_ACTION
};

enum GameDeckState
{
    UNINITIALIZED,
    NEW_GAME_1,
    LOAD_GAME_1,
};
namespace controllers
{
    namespace local
    {

        class LocalLogic : public ::Logic, public controllers::ConfigurationController
        {
        public:

            LocalLogic() : player_(nullptr), exitGame_(false), logicState_(LogicState::CHOOSE_ACTION), gameDeckState_(GameDeckState::UNINITIALIZED)
            {
            };

            std::shared_ptr<controllers::OperationController> getOperationController()
            {
                if (exitGame_)
                {
                    return nullptr;
                }
                else if (nullptr == player_)
                {
                    return std::make_shared<LocalPlayerSelectionController>(*this);
                }
                else if (nullptr == game_)
                {
                    switch (gameDeckState_)
                    {
                        case GameDeckState::UNINITIALIZED:
                            return std::make_shared<controllers::NewOrLoadController>(*this);
                        case GameDeckState::LOAD_GAME_1:
                            return nullptr;
                        case GameDeckState::NEW_GAME_1:
                            return std::make_shared<controllers::ChooseDeckController>(game_);
                    }
                }
                else if (!game_->isFinished())
                {
                    return std::make_shared<controllers::GameActionController>(*player_, *game_);
                }
                else
                {
                    return std::make_shared<LocalExitGameController>(*this);
                }
            }

            void initDemoPlayer(bool isDemoPlayer)
            {
                if (isDemoPlayer)
                {
                    player_ = std::make_shared<LocalDemoPlayer>(game_);
                }
                else
                {
                    player_ = std::make_shared<LocalUserPlayer>(game_);
                }
            }

            void setExitGame()
            {
                resetPlayer();
                exitGame_ = true;
            }

            void setContinueGame()
            {
                resetPlayer();
                exitGame_ = false;
            }

            void setLoadGame() { gameDeckState_ = GameDeckState::LOAD_GAME_1;  }

            void setNewGame() {
                gameDeckState_ = GameDeckState::NEW_GAME_1; }

            void setDeck(const std::string deckName)
            {
                game_ = std::make_shared<Game>(GameDeck(deckName));
                logicState_ = LogicState::CHOOSE_ACTION;
            }

        protected:
            void resetPlayer()
            {
                player_.reset();
                player_ = nullptr;
            }
        private:
            LogicState logicState_;
            GameDeckState gameDeckState_;
            std::shared_ptr<PlayerController> player_;
            std::shared_ptr<Game> game_;
            bool exitGame_;
        };
    }
}


#endif //KLONDIKE_LOCALLOGIC_H
