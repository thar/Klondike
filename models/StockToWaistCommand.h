#ifndef KLONDIKE_STOCKTOWAISTCOMMAND_H
#define KLONDIKE_STOCKTOWAISTCOMMAND_H


#include "KlondikeCommand.h"
#include "Stock.h"
#include "Waist.h"

class StockToWaistCommand : public KlondikeCommand
{
public:
    StockToWaistCommand(Stock& stock, Waist& waist) : KlondikeCommand(stock, waist) {}
    void execute();
    void undo();
    void __validate();

private:

};


#endif //KLONDIKE_STOCKTOWAISTCOMMAND_H
