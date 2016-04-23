#ifndef KLONDIKE_STOCKTOWAISTCOMMAND_H
#define KLONDIKE_STOCKTOWAISTCOMMAND_H


#include "KlondikeCommand.h"
#include "Stock.h"
#include "Waist.h"

class StockToWaistCommand : public KlondikeCommand
{
public:
    StockToWaistCommand(Stock& stock, Waist& waist) : stock_(stock), waist_(waist), movedCards_(0) {}
    void execute();
    void undo();
    void __validate();

private:
    Stock& stock_;
    Waist& waist_;
    unsigned int movedCards_;
};


#endif //KLONDIKE_STOCKTOWAISTCOMMAND_H
