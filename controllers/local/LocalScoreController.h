
#ifndef KLONDIKE_LOCALSCORECONTROLLER_H
#define KLONDIKE_LOCALSCORECONTROLLER_H


#include "../ScoreController.h"
#include "../../models/Game.h"

namespace controllers
{
    namespace local
    {
        class LocalScoreController : public ScoreController
        {
        public:
            LocalScoreController(std::shared_ptr<Game> game);
            int getScore();
            std::vector<int> getTopScores();
            void accept(OperationControllerVisitor& operationControllerVisitor);
        protected:
        private:
            std::shared_ptr<Game> game_;
        };
    }
}


#endif //KLONDIKE_LOCALSCORECONTROLLER_H
