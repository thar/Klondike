#ifndef KLONDIKE_WAISTTOFOUNDATIONCOMMAND_H
#define KLONDIKE_WAISTTOFOUNDATIONCOMMAND_H


#include "KlondikeCommand.h"
#include "Waist.h"
#include "Foundation.h"

class WaistToFoundationCommand : public KlondikeCommand
{
public:
    WaistToFoundationCommand(Waist& waist, Foundation& foundation, int& score) : KlondikeCommand(waist, foundation, score, 10) {}
    void execute();
    void undo();
    void __validate();
    std::shared_ptr<KlondikeCommand> clone();

private:

};


#endif //KLONDIKE_WAISTTOFOUNDATIONCOMMAND_H
