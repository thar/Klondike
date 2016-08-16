#include "Klondike.h"

Klondike::Klondike(Logic& logic, View& view) : logic_(logic), view_(view) {}
void Klondike::play()
{
    std::shared_ptr<controllers::OperationController> controller = logic_.getOperationController();
    while (controller)
    {
        view_.interact(*controller);
        controller = logic_.getOperationController();
    }
}