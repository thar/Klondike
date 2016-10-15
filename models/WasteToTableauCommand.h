#ifndef KLONDIKE_WAISTTOTABLEAU_H
#define KLONDIKE_WAISTTOTABLEAU_H

#include "KlondikeCommand.h"
#include "Waste.h"
#include "Tableau.h"

class WasteToTableauCommand : public KlondikeCommand
{
public:
    WasteToTableauCommand(Waste &waist, Tableau &tableau, int &score) : KlondikeCommand(score, 5), origin_(waist),
                                                                        destiny_(tableau)
    {
        originPile_ = Waste::pileName;
    }

    void __execute();

    void __undo();
    void accept(KlondikeCommandVisitor& visitor) { visitor.visit(*this); }

    void __validate();

    std::shared_ptr<KlondikeCommand> clone();

    std::set<std::string> getOriginPiles() { return origin_.getPilesNames(); }
    std::set<std::string> getDestinyPiles() { return destiny_.getPilesNames(); }

private:
    Waste &origin_;
    Tableau &destiny_;
};


#endif //KLONDIKE_WAISTTOTABLEAU_H
