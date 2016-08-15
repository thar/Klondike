#include "GameActionListHeader.h"

controllers::local::GameActionListHeader::GameActionListHeader(Game& game) : game_(game)
{}
void controllers::local::GameActionListHeader::accept(controllers::ActionListHeaderVisitor& visitor)
{
    visitor.visit(*this);
}
Game& controllers::local::GameActionListHeader::getGame()
{
    return game_;
}