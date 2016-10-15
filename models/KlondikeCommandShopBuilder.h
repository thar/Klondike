#ifndef KLONDIKE_KLONDIKECOMMANDSHOPBUILDER_H
#define KLONDIKE_KLONDIKECOMMANDSHOPBUILDER_H

#include "GameBoard.h"
#include "KlondikeCommandShop.h"

class KlondikeCommandShopBuilder : public KlondikeCommandVisitor
{
public:
    static KlondikeCommandShop createCommandShop(GameBoard& board, int& score);
    unsigned int getCommandIndex(KlondikeCommand& command);
    void visit(FoundationToTableauCommand& command);
    void visit(StockToWasteCommand& command);
    void visit(TableauToFoundationCommand& command);
    void visit(TableauToTableauCommand& command);
    void visit(WasteToFoundationCommand& command);
    void visit(WasteToStockCommand& command);
    void visit(WasteToTableauCommand& command);
protected:
private:
    unsigned int index_;
};


#endif //KLONDIKE_KLONDIKECOMMANDSHOPBUILDER_H
