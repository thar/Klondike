#ifndef KLONDIKE_WAISTTOSTOCKCOMMAND_H
#define KLONDIKE_WAISTTOSTOCKCOMMAND_H


#include "KlondikeCommand.h"
#include "Stock.h"
#include "Waist.h"

class WaistToStockCommand : public KlondikeCommand
{
public:
    WaistToStockCommand(Stock& stock, Waist& waist) : stock_(stock), waist_(waist) {}
    void execute();
    void undo();
    void __validate();

private:
    Stock& stock_;
    Waist& waist_;
    unsigned int faceUpCards_;
};


#endif //KLONDIKE_WAISTTOSTOCKCOMMAND_H
