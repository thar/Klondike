#ifndef KLONDIKE_GAMEACTIONLISTHEADER_H
#define KLONDIKE_GAMEACTIONLISTHEADER_H

#include "../ActionListHeader.h"
#include "ActionListHeaderVisitor.h"
#include "../../models/Game.h"

namespace controllers
{
    namespace local
    {
        class GameActionListHeader : public ActionListHeader
        {
        public:
            GameActionListHeader(Game& game);
            void accept(controllers::ActionListHeaderVisitor& visitor);
            Game& getGame();

        protected:
        private:
            Game& game_;
        };
    }
}


#endif //KLONDIKE_GAMEACTIONLISTHEADER_H
