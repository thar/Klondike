#ifndef KLONDIKE_PLAYER_H
#define KLONDIKE_PLAYER_H


#include "OperationController.h"
#include <memory>

class PlayerController
{
public:
    //TODO: All the functions to interact with the game
    virtual bool isGameFinished() = 0;
    virtual std::shared_ptr<controllers::OperationController> getOperationController() = 0;
    virtual void setLoadGame() = 0;
    virtual void setNewGame() = 0;
    virtual void setDeck(std::string deck) = 0;
    virtual void undoMovement() = 0;
    virtual void redoMovement() = 0;
protected:
private:
};


#endif //KLONDIKE_PLAYER_H
