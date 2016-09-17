#ifndef KLONDIKE_STOCKTOWAISTCOMMAND_H
#define KLONDIKE_STOCKTOWAISTCOMMAND_H


#include "KlondikeCommand.h"
#include "Stock.h"
#include "Waist.h"

class StockToWaistCommand : public KlondikeCommand
{
public:
    StockToWaistCommand(Stock &stock, Waist &waist, int &score) : KlondikeCommand(score, 0), origin_(stock),
                                                                  destiny_(waist)
    {
        originPile_ = Stock::pileName;
        destinyPile_ = Waist::pileName;
    }
    void execute();
    void undo();
    void accept(KlondikeCommandVisitor& visitor) { visitor.visit(*this); }
    void __validate();
    std::shared_ptr<KlondikeCommand> clone();

private:
    Stock &origin_;
    Waist &destiny_;
    Pile destinyPileCards;

};


#endif //KLONDIKE_STOCKTOWAISTCOMMAND_H
