#ifndef KLONDIKE_KLONDIKECOMMANDSHOP_H
#define KLONDIKE_KLONDIKECOMMANDSHOP_H


#include <vector>
#include <memory>
#include "KlondikeCommand.h"
#include "GameBoard.h"

class KlondikeCommandShop
{
public:
    KlondikeCommandShop();
    void addCommand(std::shared_ptr<KlondikeCommand> command);
    std::shared_ptr<KlondikeCommand> getCommand(unsigned int commandIndex);
    //auto begin() { return commands_.begin(); }
    //auto end() { return commands_.end(); }
protected:
private:
    std::vector< std::shared_ptr<KlondikeCommand> > commands_;

};


#endif //KLONDIKE_KLONDIKECOMMANDSHOP_H
