
#ifndef KLONDIKE_SCOREVIEW_H
#define KLONDIKE_SCOREVIEW_H

#include "../../controllers/local/LocalScoreController.h"

namespace views
{
    namespace console
    {
        class ScoreView
        {
        public:
            void interact(controllers::local::LocalScoreController& controller);
        protected:
        private:
        };
    }
}


#endif //KLONDIKE_SCOREVIEW_H
