#ifndef KLONDIKE_WAISTTOFOUNDATIONCOMMAND_H
#define KLONDIKE_WAISTTOFOUNDATIONCOMMAND_H


#include "KlondikeCommand.h"
#include "Waist.h"
#include "Foundation.h"

class WaistToFoundationCommand : public KlondikeCommand
{
public:
    WaistToFoundationCommand(Waist &waist, Foundation &foundation, int &score) : KlondikeCommand(score, 10),
                                                                                 origin_(waist), destiny_(foundation)
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
    Foundation &destiny_;

};


#endif //KLONDIKE_WAISTTOFOUNDATIONCOMMAND_H
