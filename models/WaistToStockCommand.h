#ifndef KLONDIKE_WAISTTOSTOCKCOMMAND_H
#define KLONDIKE_WAISTTOSTOCKCOMMAND_H


#include "KlondikeCommand.h"
#include "Stock.h"
#include "Waist.h"

class WaistToStockCommand : public KlondikeCommand
{
public:
    WaistToStockCommand(Stock& stock, Waist& waist) : KlondikeCommand(waist, stock) {}
    void execute();
    void undo();
    void __validate();

private:

};


#endif //KLONDIKE_WAISTTOSTOCKCOMMAND_H
