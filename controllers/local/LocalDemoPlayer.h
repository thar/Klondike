#ifndef KLONDIKE_LOCALDEMOPLAYER_H
#define KLONDIKE_LOCALDEMOPLAYER_H


#include "LocalPlayerController.h"

class LocalDemoPlayer : public LocalPlayerController
{
public:
    LocalDemoPlayer() { state_ = State::GAME_FINISHED; }
    std::shared_ptr<controllers::OperationController> getOperationController()
    {
        return nullptr;
    }
    void getOriginPile() {}
    void getDestinyPile() {}
    void visit(FoundationToTableauCommand& command) {}
    void visit(StockToWaistCommand& command) {}
    void visit(TableauToFoundationCommand& command) {}
    void visit(TableauToTableauCommand& command) {}
    void visit(WaistToFoundationCommand& command) {}
    void visit(WaistToStockCommand& command)  {}
    void visit(WaistToTableauCommand& command) {}
protected:
private:
};


#endif //KLONDIKE_LOCALDEMOPLAYER_H
