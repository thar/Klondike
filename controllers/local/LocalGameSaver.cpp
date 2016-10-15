
#include "LocalGameSaver.h"
#include "../../models/KlondikeCommandShopBuilder.h"

void controllers::local::LocalGameSaver::addCommand(KlondikeCommand &command)
{
    commandList_.push_back(CommandValues());
    commandList_.back().index = KlondikeCommandShopBuilder().getCommandIndex(command);
    command.save(*this);
}

void controllers::local::LocalGameSaver::addOrigin(std::string origin)
{
    commandList_.back().origin = origin;
}

void controllers::local::LocalGameSaver::addDestiny(std::string destiny)
{
    commandList_.back().destiny = destiny;
}

void controllers::local::LocalGameSaver::addNumberOfCards(unsigned int numberOfCards)
{
    commandList_.back().numberOfCards = numberOfCards;
}

controllers::local::LocalGameSaver::LocalGameSaver(std::string fileName) :
        fileName_(fileName)
{
}

void controllers::local::LocalGameSaver::addRandomSeed(unsigned int seed)
{
    seed_ = seed;
}

void controllers::local::LocalGameSaver::addDeckPath(std::string deckPath)
{
    deckFilePath_ = deckPath;
}
