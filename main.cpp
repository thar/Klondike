#include "controllers/local/LocalLogic.h"
#include "views/console/ConsoleView.h"
#include "Klondike.h"

int main() {

    views::console::ConsoleView view;
    controllers::local::LocalLogic logic;
    Klondike klondike(logic, view);
    klondike.play();

    return 0;
}