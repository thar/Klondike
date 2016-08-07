#ifndef KLONDIKE_KLONDIKE_H
#define KLONDIKE_KLONDIKE_H

#include <memory>

#include "View.h"
#include "Logic.h"

class Klondike
{
public:
    Klondike(Logic& logic, View& view) : logic_(logic), view_(view) {};
    void play()
    {
        std::shared_ptr<controllers::OperationController> controller = logic_.getOperationController();
        while (controller)
        {
            view_.interact(*controller);
            controller = logic_.getOperationController();
        }
    };

protected:
private:
    Logic& logic_;
    View& view_;

};


#endif //KLONDIKE_KLONDIKE_H
