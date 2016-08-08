#ifndef KLONDIKE_KLONIKECOMMANDVISITOR_H
#define KLONDIKE_KLONIKECOMMANDVISITOR_H

class FoundationToTableauCommand;
class StockToWaistCommand;
class TableauToFoundationCommand;
class TableauToTableauCommand;
class WaistToFoundationCommand;
class WaistToStockCommand;
class WaistToTableauCommand;

class KlondikeCommandVisitor
{
public:
    virtual void visit(FoundationToTableauCommand& command) = 0;
    virtual void visit(StockToWaistCommand& command) = 0;
    virtual void visit(TableauToFoundationCommand& command) = 0;
    virtual void visit(TableauToTableauCommand& command) = 0;
    virtual void visit(WaistToFoundationCommand& command) = 0;
    virtual void visit(WaistToStockCommand& command) = 0;
    virtual void visit(WaistToTableauCommand& command) = 0;
};


#endif //KLONDIKE_KLONIKECOMMANDVISITOR_H
