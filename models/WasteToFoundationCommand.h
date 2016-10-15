#ifndef KLONDIKE_WAISTTOFOUNDATIONCOMMAND_H
#define KLONDIKE_WAISTTOFOUNDATIONCOMMAND_H


#include "KlondikeCommand.h"
#include "Waste.h"
#include "Foundation.h"

class WasteToFoundationCommand : public KlondikeCommand
{
public:
    WasteToFoundationCommand(Waste &waist, Foundation &foundation, int &score) : KlondikeCommand(score, 10),
                                                                                 origin_(waist), destiny_(foundation)
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
    Foundation &destiny_;

};


#endif //KLONDIKE_WAISTTOFOUNDATIONCOMMAND_H
