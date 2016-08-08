#ifndef KLONDIKE_WAISTTOSTOCKCOMMAND_H
#define KLONDIKE_WAISTTOSTOCKCOMMAND_H


#include "KlondikeCommand.h"
#include "Stock.h"
#include "Waist.h"

class WaistToStockCommand : public KlondikeCommand
{
public:
    WaistToStockCommand(Stock &stock, Waist &waist, int &score) : KlondikeCommand(score, 0), origin_(stock),
                                                                  destiny_(waist)
    {
        originPile_ = Waist::pileName;
        destinyPile_ = Stock::pileName;
    }
    void execute();
    void undo();
    void accept(KlondikeCommandVisitor& visitor) { visitor.visit(*this); }
    void __validate();
    std::shared_ptr<KlondikeCommand> clone();

private:
    Stock &origin_;
    Waist &destiny_;

};


#endif //KLONDIKE_WAISTTOSTOCKCOMMAND_H
