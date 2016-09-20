
#include <iostream>
#include "ScoreView.h"

void views::console::ScoreView::interact(controllers::local::LocalScoreController &controller)
{
    std::cout << "tu puntuación: " << controller.getScore() << std::endl;
}
