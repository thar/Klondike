
#include "LocalUndoListSaver.h"
#include "../../models/KlondikeCommandShopBuilder.h"

void controllers::local::LocalUndoListSaver::addCommand(KlondikeCommand &command)
{
    commandListValues_ << std::string("COMMAND: ") << KlondikeCommandShopBuilder().getCommandIndex(command) << std::endl;
    command.save(*this);
}

void controllers::local::LocalUndoListSaver::addOrigin(std::string origin)
{
    commandListValues_ << std::string("ORIGIN: ") << origin << std::endl;
}

void controllers::local::LocalUndoListSaver::addDestiny(std::string destiny)
{
    commandListValues_ << std::string("DESTINY: ") << destiny << std::endl;
}

void controllers::local::LocalUndoListSaver::addNumberOfCards(unsigned int numberOfCards)
{
    commandListValues_ << std::string("CARDS: ") << numberOfCards << std::endl;
}

controllers::local::LocalUndoListSaver::LocalUndoListSaver(std::string fileName) :
        commandListValues_(fileName, std::ofstream::out)
{
}

controllers::local::LocalUndoListSaver::~LocalUndoListSaver()
{
    commandListValues_.close();
}
