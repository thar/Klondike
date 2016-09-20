#ifndef KLONDIKE_TABLEAUTOFOUNDATIONCOMMAND_H
#define KLONDIKE_TABLEAUTOFOUNDATIONCOMMAND_H


#include "KlondikeCommand.h"
#include "Tableau.h"
#include "Foundation.h"

class TableauToFoundationCommand : public KlondikeCommand
{
public:
    TableauToFoundationCommand(Tableau &tableau, Foundation &foundation, int &score) : KlondikeCommand(score, 10),
                                                                                       origin_(tableau),
                                                                                       destiny_(foundation),
                                                                                       turnOriginCard_(false)
    { }

    void execute();

    void undo();
    void accept(KlondikeCommandVisitor& visitor) { visitor.visit(*this); }

    void __validate();

    std::shared_ptr<KlondikeCommand> clone();

    std::set<std::string> getOriginPiles() { return origin_.getPilesNames(); }
    std::set<std::string> getDestinyPiles() { return destiny_.getPilesNames(); }

private:
    Tableau &origin_;
    Foundation &destiny_;
    bool turnOriginCard_;
};


#endif //KLONDIKE_TABLEAUTOFOUNDATIONCOMMAND_H
