#ifndef KLONDIKE_PLAYER_H
#define KLONDIKE_PLAYER_H


#include "OperationController.h"
#include <memory>

class PlayerController
{
public:
    virtual bool isGameFinished() = 0;
    virtual std::shared_ptr<controllers::OperationController> getOperationController() = 0;
    virtual void setLoadGame() = 0;
    virtual void setNewGame() = 0;
    virtual void setDeck(std::string deck) = 0;
    virtual void undoMovement() = 0;
    virtual void redoMovement() = 0;
    virtual void giveUpGame() = 0;
    virtual void saveGame() = 0;
    virtual void executeKlondikeCommand(unsigned int action) = 0;
    virtual void getOriginPile() = 0;
    virtual void getDestinyPile() = 0;
protected:
private:
};


#endif //KLONDIKE_PLAYER_H
