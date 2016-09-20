#ifndef KLONDIKE_WAISTTOTABLEAU_H
#define KLONDIKE_WAISTTOTABLEAU_H

#include "KlondikeCommand.h"
#include "Waist.h"
#include "Tableau.h"

class WaistToTableauCommand : public KlondikeCommand
{
public:
    WaistToTableauCommand(Waist &waist, Tableau &tableau, int &score) : KlondikeCommand(score, 5), origin_(waist),
                                                                        destiny_(tableau)
    {
        originPile_ = Waist::pileName;
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
    Tableau &destiny_;
};


#endif //KLONDIKE_WAISTTOTABLEAU_H
