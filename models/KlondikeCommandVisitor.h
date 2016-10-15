#ifndef KLONDIKE_KLONIKECOMMANDVISITOR_H
#define KLONDIKE_KLONIKECOMMANDVISITOR_H

class FoundationToTableauCommand;
class StockToWasteCommand;
class TableauToFoundationCommand;
class TableauToTableauCommand;
class WasteToFoundationCommand;
class WasteToStockCommand;
class WasteToTableauCommand;

class KlondikeCommandVisitor
{
public:
    virtual void visit(FoundationToTableauCommand& command) = 0;
    virtual void visit(StockToWasteCommand& command) = 0;
    virtual void visit(TableauToFoundationCommand& command) = 0;
    virtual void visit(TableauToTableauCommand& command) = 0;
    virtual void visit(WasteToFoundationCommand& command) = 0;
    virtual void visit(WasteToStockCommand& command) = 0;
    virtual void visit(WasteToTableauCommand& command) = 0;
};


#endif //KLONDIKE_KLONIKECOMMANDVISITOR_H
