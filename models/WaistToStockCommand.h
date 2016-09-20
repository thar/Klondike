#ifndef KLONDIKE_WAISTTOSTOCKCOMMAND_H
#define KLONDIKE_WAISTTOSTOCKCOMMAND_H


#include "KlondikeCommand.h"
#include "Stock.h"
#include "Waist.h"

class WaistToStockCommand : public KlondikeCommand
{
public:
    WaistToStockCommand(Stock &stock, Waist &waist, int &score) : KlondikeCommand(score, 0), origin_(waist),
                                                                  destiny_(stock)
    {
        originPile_ = Waist::pileName;
        destinyPile_ = Stock::pileName;
    }
    void execute();
    void undo();
    void accept(KlondikeCommandVisitor& visitor) { visitor.visit(*this); }
    void __validate();
    std::shared_ptr<KlondikeCommand> clone();

    std::set<std::string> getOriginPiles() { return origin_.getPilesNames(); }
    std::set<std::string> getDestinyPiles() { return destiny_.getPilesNames(); }

private:
    Waist &origin_;
    Stock &destiny_;

};


#endif //KLONDIKE_WAISTTOSTOCKCOMMAND_H
