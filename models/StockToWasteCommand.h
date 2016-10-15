#ifndef KLONDIKE_STOCKTOWAISTCOMMAND_H
#define KLONDIKE_STOCKTOWAISTCOMMAND_H


#include "KlondikeCommand.h"
#include "Stock.h"
#include "Waste.h"

class StockToWasteCommand : public KlondikeCommand
{
public:
    StockToWasteCommand(Stock &stock, Waste &waist, int &score) : KlondikeCommand(score, 0), origin_(stock),
                                                                  destiny_(waist)
    {
        originPile_ = Stock::pileName;
        destinyPile_ = Waste::pileName;
    }
    void __execute();
    void __undo();
    void accept(KlondikeCommandVisitor& visitor) { visitor.visit(*this); }
    void __validate();
    std::shared_ptr<KlondikeCommand> clone();

    std::set<std::string> getOriginPiles() { return origin_.getPilesNames(); }
    std::set<std::string> getDestinyPiles() { return destiny_.getPilesNames(); }

private:
    Stock &origin_;
    Waste &destiny_;
    Pile destinyPileCards;

};


#endif //KLONDIKE_STOCKTOWAISTCOMMAND_H
