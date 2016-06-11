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
    void __validate();
    std::shared_ptr<KlondikeCommand> clone();

private:
    Waist &origin_;
    Foundation &destiny_;

};


#endif //KLONDIKE_WAISTTOFOUNDATIONCOMMAND_H
