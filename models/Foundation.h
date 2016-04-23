#ifndef KLONDIKE_FOUNDATION_H
#define KLONDIKE_FOUNDATION_H


#include <memory>
#include "Pile.h"
#include "GameDeck.h"

class Foundation
{
public:
    Foundation(int numberOfSuits) : foundationPiles_(numberOfSuits)
    {};
    void pushAction()
    {
    };
    void popAction()
    {};
protected:
private:
    std::vector<Pile> foundationPiles_;

    friend std::ostream& operator<<(std::ostream& os, const Foundation& obj);
};


#endif //KLONDIKE_FOUNDATION_H
