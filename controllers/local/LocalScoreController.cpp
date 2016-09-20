
#include "LocalScoreController.h"

controllers::local::LocalScoreController::LocalScoreController(std::shared_ptr<Game> game) : game_(game)
{
}

int controllers::local::LocalScoreController::getScore()
{
    return game_->getScore();
}

std::vector<int> controllers::local::LocalScoreController::getTopScores()
{
    return std::vector<int>();
}

void
controllers::local::LocalScoreController::accept(controllers::OperationControllerVisitor &operationControllerVisitor)
{
    operationControllerVisitor.visit(*this);
}
