#ifndef KLONDIKE_KLONDIKE_H
#define KLONDIKE_KLONDIKE_H

#include <memory>

#include "View.h"
#include "Logic.h"

class Klondike
{
public:
    Klondike(Logic& logic, View& view);
    void play();

protected:
private:
    Logic& logic_;
    View& view_;

};


#endif //KLONDIKE_KLONDIKE_H
