#ifndef KLONDIKE_LOCALGAMEACTIONCONTROLLER_H
#define KLONDIKE_LOCALGAMEACTIONCONTROLLER_H

#include "../GameActionController.h"
#include "../PlayerController.h"
#include "../ConfigurationController.h"
#include "LocalDemoPlayer.h"
#include "LocalUserPlayer.h"
#include "GameActionsInitializer.h"

namespace controllers
{
    namespace local
    {
        class LocalGameActionController : public controllers::GameActionController
        {
        public:
            LocalGameActionController(ConfigurationController &configurationController)
                    : configurationController_(configurationController),
                      playerController_(nullptr), game_(nullptr)
            {
            }

            Game& getGame() const
            {
                return *game_;
            }

            void newGame(std::string deckPath)
            {
                game_ = std::make_shared<Game>(deckPath);
                GameActionsInitializer(*playerController_, *game_, configurationController_);
            }

            std::shared_ptr<PlayerController> getPlayerController() { return playerController_; }

            void setPlayer(std::shared_ptr<PlayerController> player) { playerController_ = player; }

            void initDemoPlayer(bool isDemoPlayer)
            {
                if (isDemoPlayer)
                    setPlayer(std::make_shared<LocalDemoPlayer>(*this));
                else
                    setPlayer(std::make_shared<LocalUserPlayer>(*this, configurationController_));
            }

            std::shared_ptr<KlondikeCommand> getKlondikeCommand(unsigned int index)
            {
                return game_->getCommand(index);
            }

        protected:
        private:
            ConfigurationController& configurationController_;
            std::shared_ptr<PlayerController> playerController_;
            std::shared_ptr<Game> game_;
        };
    }
}


#endif //KLONDIKE_LOCALGAMEACTIONCONTROLLER_H
