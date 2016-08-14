#ifndef KLONDIKE_LOCALLOGIC_H
#define KLONDIKE_LOCALLOGIC_H

#include <memory>
#include "../GameController.h"
#include "../ActionListController.h"
#include "../AutomaticActionListController.h"
#include "../AbandonController.h"
#include "../ExitController.h"
#include "DeckControllerBuilder.h"
#include "PlayerChooseControllerBuilder.h"

#include "../../models/GameDeck.h"
#include "../../models/Game.h"
#include "../../Logic.h"

namespace controllers
{
    namespace local
    {
        class LocalLogic : public ::Logic, public controllers::GameController
        {
        public:
            LocalLogic() : playerType_(UNINITIALIZED), deckController_(nullptr), gameActionsController_(nullptr),
                           loadGameController_(nullptr), abandonController_(nullptr), exitController_(nullptr),
                           game_(nullptr), abruptExit_(false)
            {
                playerChooseController_ = PlayerChooseControllerBuilder(*this).getPlayerChooseController();
            };

            std::shared_ptr<controllers::OperationController> getOperationController()
            {
                if(UNINITIALIZED == playerType_)
                    return playerChooseController_;
                else if(!game_)
                {
                    if (!loadGameController_)
                        return deckController_;
                    else
                        return loadGameController_;
                }
                else if(!game_->isFinished())
                    return gameActionsController_;
                else if(!abruptExit_)
                    return abandonController_;
                else
                    return exitController_;
            }

            void setPlayer(PlayerType playerType)
            {
                playerType_ = playerType;
                deckController_ = DeckControllerBuilder(*this, playerType_).getDeckController();
                //loadGameController_ = LoadGameControllerBuilder(*playerController_, *this).getGameControllerBuilder():
            }
            void setDeck(std::string deckPath)
            {
                game_ = std::make_shared<Game>(GameDeck(deckPath));
                //gameActionsController_ = GameActionsControllerBuilder(game_, playerType_).getGameActionsController();
            }
            void exitGame()
            {
                playerType_ = UNINITIALIZED;
                game_.reset();
                abruptExit_ = true;
            }
            void abandonGame()
            {
                playerType_ = UNINITIALIZED;
                game_.reset();
                abruptExit_ = false;
            }

        protected:

        private:
            PlayerType playerType_;
            std::shared_ptr<controllers::ActionListController> playerChooseController_;
            std::shared_ptr<controllers::ActionListController> deckController_;
            std::shared_ptr<controllers::ActionListController> gameActionsController_;
            std::shared_ptr<controllers::ActionListController> loadGameController_;
            std::shared_ptr<controllers::AbandonController> abandonController_;
            std::shared_ptr<controllers::ExitController> exitController_;
            std::shared_ptr<Game> game_;
            bool abruptExit_;
        };
    }
}


#endif //KLONDIKE_LOCALLOGIC_H
