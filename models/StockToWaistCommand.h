#ifndef KLONDIKE_STOCKTOWAISTCOMMAND_H
#define KLONDIKE_STOCKTOWAISTCOMMAND_H


#include "KlondikeCommand.h"
#include "Stock.h"
#include "Waist.h"

class StockToWaistCommand : public KlondikeCommand
{
public:
    StockToWaistCommand(Stock& stock, Waist& waist, int& score) : KlondikeCommand(stock, waist, score, 0) {}
    void execute();
    void undo();
    void __validate();
    std::shared_ptr<KlondikeCommand> clone();

private:

};


#endif //KLONDIKE_STOCKTOWAISTCOMMAND_H
