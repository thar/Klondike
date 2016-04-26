#include "KlondikeCommandShop.h"

KlondikeCommandShop::KlondikeCommandShop()
{
}

void KlondikeCommandShop::addCommand(std::shared_ptr<KlondikeCommand> command)
{
    commands_.push_back(command);
}

std::shared_ptr<KlondikeCommand> KlondikeCommandShop::getCommand(unsigned int commandIndex)
{
    return commands_[commandIndex]->clone();
}