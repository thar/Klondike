#ifndef KLONDIKE_LOCALLOGIC_H
#define KLONDIKE_LOCALLOGIC_H

#include <memory>
#include "../../Logic.h"
#include "LocalDemoPlayer.h"
#include "LocalUserPlayer.h"
#include "../Player.h"
#include "LocalOperationController.h"
#include "LocalPlayerSelectionController.h"
#include "LocalExitGameController.h"
#include "State.h"

namespace controllers
{
    namespace local
    {

        class LocalLogic : public ::Logic, public LocalConfigurationController
        {
        public:

            LocalLogic() : player_(nullptr), exitGame_(false)
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
                else if (!player_->isGameFinished())
                {
                    return player_->getOperationController();
                }
                else
                {
                    return std::make_shared<LocalExitGameController>(*this);
                }
                /*
                switch (state_)
                {
                    case ASK_PLAYERS:
                        return localPlayerSelectionController_;
                        break;
                    case CHOOSE_NEW_OR_LOAD:
                        break;
                    case ASK_DECK:
                        return localDeckSelectionController_;
                        break;
                    case ASK_LOAD:
                        break;
                    case IN_GAME:
                        break;
                    case SAVE:
                        return localSaveGameController_;
                        break;
                    case GIVE_UP:
                        return localGiveUpGameController_;
                        break;
                    case EXIT:
                        return localExitGameController_;
                        break;
                }
                */
            }

            void initDemoPlayer(bool isDemoPlayer)
            {
                if (isDemoPlayer)
                {
                    player_ = std::make_shared<LocalDemoPlayer>();
                }
                else
                {
                    player_ = std::make_shared<LocalUserPlayer>();
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

        protected:
            void resetPlayer()
            {
                player_.reset();
                player_ = nullptr;
            }
        private:
            std::shared_ptr<Player> player_;
            bool exitGame_;
            //State state_;
            //std::shared_ptr<Game> game_;
            //std::shared_ptr<LocalPlayerSelectionController> localPlayerSelectionController_;
            /*
            std::shared_ptr<LocalLoadAskController> localLoadAskController_;
            std::shared_ptr<LocalNewGameController> localNewGameController_;
            std::shared_ptr<LocalLoadGameController> localLoadGameController_;
            std::shared_ptr<LocalDeckSelectionController> localDeckSelectionController_;
            std::shared_ptr<LocalStartGameController> localStartGameController_;
            std::shared_ptr<LocalGameActionController> localGameActionController_;
            std::shared_ptr<LocalSaveGameController> localSaveGameController_;
            std::shared_ptr<LocalGiveUpGameController> localGiveUpGameController_;
            */
            //std::shared_ptr<LocalExitGameController> localExitGameController_;
        };
    }
}


#endif //KLONDIKE_LOCALLOGIC_H
