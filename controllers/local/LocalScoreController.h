
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
            void addScore(int score);
            void load();
            void save();

            template<class Archive>
            void serialize(Archive & archive)
            {
                archive(topScores_);
            }
        protected:
        private:
            static std::string topScoresPath;
            std::shared_ptr<Game> game_;
            std::vector<int> topScores_;
        };
    }
}


#endif //KLONDIKE_LOCALSCORECONTROLLER_H
