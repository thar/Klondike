#include "StringActionListHeader.h"

controllers::local::StringActionListHeader::StringActionListHeader(std::string menuHeader) : menuHeader_(menuHeader)
{}
void controllers::local::StringActionListHeader::accept(controllers::ActionListHeaderVisitor& visitor)
{
    visitor.visit(*this);
}
std::string controllers::local::StringActionListHeader::getMenuHeader()
{
    return menuHeader_;
}