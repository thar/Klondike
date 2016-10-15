
#include <iostream>
#include <Localization.h>
#include "ScoreView.h"

void views::console::ScoreView::interact(controllers::local::LocalScoreController &controller)
{
    Localization::getInstance().getValue(localization::TOP_SCORE);
    std::cout << Localization::getInstance().getValue(localization::SCORE) << " -> " << controller.getScore() << std::endl;
    std::cout << std::endl;
    std::cout << Localization::getInstance().getValue(localization::TOP_SCORE) << std::endl;
    unsigned int idx = 0;
    for (auto& score : controller.getTopScores())
    {
        std::cout << ++idx << ". " << score << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
