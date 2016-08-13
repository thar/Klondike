#ifndef KLONDIKE_LOCALDEMOPLAYER_H
#define KLONDIKE_LOCALDEMOPLAYER_H


#include "LocalPlayerController.h"

namespace controllers
{
    namespace local
    {
        class LocalDemoPlayer : public LocalPlayerController
        {
        public:
            LocalDemoPlayer(controllers::GameActionController &gameActionController)
                    : LocalPlayerController(gameActionController)
            { }

            std::shared_ptr<MenuEntry> getRandomDeck()
            { return availableDecks_[0]; }

            std::shared_ptr<MenuEntry> getRandomMove()
            { return nullptr; }

            void accept(PlayerControllerVisitor &playerControllerVisitor)
            {
                playerControllerVisitor.visit(*this);
            }

        protected:
        private:
        };
    }
}


#endif //KLONDIKE_LOCALDEMOPLAYER_H
