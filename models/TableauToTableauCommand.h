#ifndef KLONDIKE_TABLEAUTOTABLEAUCOMMAND_H
#define KLONDIKE_TABLEAUTOTABLEAUCOMMAND_H


#include "KlondikeCommand.h"
#include "Tableau.h"

class TableauToTableauCommand : public KlondikeCommand
{
public:
    TableauToTableauCommand(Tableau &tableauOrigin, Tableau &tableauDestiny, int &score) : KlondikeCommand(score, 0),
                                                                                           origin_(tableauOrigin),
                                                                                           destiny_(tableauDestiny)
    { }

    void execute();

    void undo();

    void __validate();

    std::shared_ptr<KlondikeCommand> clone();

private:
    Tableau &origin_;
    Tableau &destiny_;
};


#endif //KLONDIKE_TABLEAUTOTABLEAUCOMMAND_H
