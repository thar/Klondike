#include "LocalScoreController.h"
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <cereal/archives/json.hpp>
#include "pathUtils.h"
#include <algorithm>
#include <fstream>

std::string controllers::local::LocalScoreController::topScoresPath = ".topScores";

controllers::local::LocalScoreController::LocalScoreController(std::shared_ptr<Game> game) : game_(game)
{
    load();
    addScore(game_->getScore());
    save();
}

int controllers::local::LocalScoreController::getScore()
{
    return game_->getScore();
}

std::vector<int> controllers::local::LocalScoreController::getTopScores()
{
    return topScores_;
}

void
controllers::local::LocalScoreController::accept(controllers::OperationControllerVisitor &operationControllerVisitor)
{
    operationControllerVisitor.visit(*this);
}

void controllers::local::LocalScoreController::load()
{
    if (fileExists(topScoresPath))
    {
        std::ifstream inputstream(topScoresPath);
        {
            cereal::JSONInputArchive input(inputstream);
            input(*this);
        }
        inputstream.close();
    }
}

void controllers::local::LocalScoreController::save()
{
    std::ofstream outputstream(topScoresPath, std::ofstream::out);
    {
        cereal::JSONOutputArchive output(outputstream);
        output(cereal::make_nvp("top scores", *this));
    }
    outputstream.close();
}

void controllers::local::LocalScoreController::addScore(int score)
{
    if (score > 0)
        topScores_.push_back(score);
    std::sort(topScores_.begin(), topScores_.end(), std::greater<int>());
    if (topScores_.size() > 10)
        topScores_.erase(topScores_.begin() + 10, topScores_.end());
}
