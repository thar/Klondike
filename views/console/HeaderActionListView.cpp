#include <iostream>
#include "HeaderActionListView.h"

void views::console::HeaderActionListView::show(controllers::ActionListHeader& header)
{
    header.accept(*this);
}
void views::console::HeaderActionListView::visit(controllers::local::StringActionListHeader & header)
{
    std::cout << header.getMenuHeader() << std::endl;
}
void views::console::HeaderActionListView::visit(controllers::local::GameActionListHeader & header)
{
    std::cout << header.getGame() << std::endl;
}