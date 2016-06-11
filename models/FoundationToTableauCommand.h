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

    void execute();

    void undo();

    void __validate();

    std::shared_ptr<KlondikeCommand> clone();

private:
    Foundation &origin_;
    Tableau &destiny_;
};


#endif //KLONDIKE_FOUNDATIONTOTABLEAUCOMMAND_H
