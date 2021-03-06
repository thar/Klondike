#ifndef KLONDIKE_FOUNDATIONTOTABLEAUCOMMAND_H
#define KLONDIKE_FOUNDATIONTOTABLEAUCOMMAND_H


#include "Foundation.h"
#include "Tableau.h"
#include "KlondikeCommand.h"

class FoundationToTableauCommand : public KlondikeCommand
{
public:
    FoundationToTableauCommand(Foundation &foundation, Tableau &tableau, int &score) : KlondikeCommand(score, -15),
                                                                                       origin_(foundation),
                                                                                       destiny_(tableau)
    { }

    void __execute();

    void __undo();

    void accept(KlondikeCommandVisitor& visitor) { visitor.visit(*this); }

    void __validate();

    std::shared_ptr<KlondikeCommand> clone();

    std::set<std::string> getOriginPiles() { return origin_.getPilesNames(); }
    std::set<std::string> getDestinyPiles() { return destiny_.getPilesNames(); }

private:
    Foundation &origin_;
    Tableau &destiny_;
};


#endif //KLONDIKE_FOUNDATIONTOTABLEAUCOMMAND_H
