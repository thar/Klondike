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
#include "LocalGameActionController.h"

enum LogicState
{
    INIT_PLAYER,
    INIT_GAME,
    CHOOSE_ACTION,
    EXEC_ACTION,
    EXIT,
    EXIT_ABRUPT
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

            LocalLogic() : logicState_(LogicState::INIT_PLAYER),
                           gameDeckState_(GameDeckState::UNINITIALIZED),
                           localGameActionController_(std::make_shared<LocalGameActionController>(*this))
            {
            };

            std::shared_ptr<controllers::OperationController> getOperationController()
            {
                switch(logicState_)
                {
                    case INIT_PLAYER:
                        logicState_ = INIT_GAME;
                        return std::make_shared<LocalPlayerSelectionController>(*this, *localGameActionController_);
                    case INIT_GAME:
                        return getInitGameController();
                    case CHOOSE_ACTION:
                        return localGameActionController_;
                    case EXEC_ACTION:
                        return nullptr;
                    case EXIT:
                        return std::make_shared<LocalExitGameController>(*this);
                    case EXIT_ABRUPT:
                        return nullptr;
                }
            }

            void giveUpGame()
            {
                logicState_ = EXIT;
            }
            void setExitGame()
            {
                logicState_ = EXIT_ABRUPT;
            }

            void setContinueGame()
            {
                logicState_ = INIT_PLAYER;
            }

            void setLoadGame()
            {
                gameDeckState_ = GameDeckState::LOAD_GAME_1;
            }

            void setNewGame()
            {
                gameDeckState_ = GameDeckState::NEW_GAME_1;
            }

            void setSelectDeck()
            {
                logicState_ = INIT_GAME;
                gameDeckState_ = GameDeckState::NEW_GAME_1;
            }

        protected:

            std::shared_ptr<controllers::OperationController> getInitGameController()
            {
                switch (gameDeckState_)
                {
                    case GameDeckState::UNINITIALIZED:
                        return std::make_shared<controllers::NewOrLoadController>(*this);
                    case GameDeckState::LOAD_GAME_1:
                        return nullptr;
                    case GameDeckState::NEW_GAME_1:
                        logicState_ = LogicState::CHOOSE_ACTION;
                        return std::make_shared<controllers::ChooseDeckController>(*(localGameActionController_->getPlayerController()));
                }
            }

        private:
            LogicState logicState_;
            GameDeckState gameDeckState_;
            std::shared_ptr<LocalGameActionController> localGameActionController_;
        };
    }
}


#endif //KLONDIKE_LOCALLOGIC_H
