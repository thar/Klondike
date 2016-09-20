
#ifndef KLONDIKE_SCORECONTROLLER_H
#define KLONDIKE_SCORECONTROLLER_H

#include "OperationController.h"
#include <vector>

namespace controllers
{
    class ScoreController : public OperationController
    {
    public:
        virtual int getScore() = 0;
        virtual std::vector<int> getTopScores() = 0;
    protected:
    private:
    };
}


#endif //KLONDIKE_SCORECONTROLLER_H
