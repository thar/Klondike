#ifndef KLONDIKE_WAISTTOSTOCKCOMMAND_H
#define KLONDIKE_WAISTTOSTOCKCOMMAND_H


#include "KlondikeCommand.h"
#include "Stock.h"
#include "Waist.h"

class WaistToStockCommand : public KlondikeCommand
{
public:
    WaistToStockCommand(Stock& stock, Waist& waist, int& score) : KlondikeCommand(waist, stock, score, 0) {}
    void execute();
    void undo();
    void __validate();
    std::shared_ptr<KlondikeCommand> clone();

private:

};


#endif //KLONDIKE_WAISTTOSTOCKCOMMAND_H
