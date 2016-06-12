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

    void __validate();

    std::shared_ptr<KlondikeCommand> clone();

private:
    Tableau &origin_;
    Foundation &destiny_;
    bool turnOriginCard_;
};


#endif //KLONDIKE_TABLEAUTOFOUNDATIONCOMMAND_H
