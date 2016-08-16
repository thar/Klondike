#include "KlondikeCommandGameActionView.h"
#include <iostream>

void views::console::KlondikeCommandGameActionView::interact(controllers::local::KlondikeCommandGameAction &entry)
{
    entry.accept(*this);
}
void views::console::KlondikeCommandGameActionView::visit(FoundationToTableauCommand& command)
{
    command.setOriginPile(std::to_string(getUserInput("Origin pile? [1,7]: ")));
    command.setCardsToMove(getUserInput( "Number of cards to move? [X,X]: "));
    command.setDestinyPile(std::to_string(getUserInput("Destiny pile? [1,7]: ")));
}
void views::console::KlondikeCommandGameActionView::visit(StockToWaistCommand& command)
{

}
void views::console::KlondikeCommandGameActionView::visit(TableauToFoundationCommand& command)
{
    command.setOriginPile(std::to_string(getUserInput("Origin pile? [1,7]: ")));
}
void views::console::KlondikeCommandGameActionView::visit(TableauToTableauCommand& command)
{
    command.setOriginPile(std::to_string(getUserInput("Origin pile? [1,7]: ")));
    command.setCardsToMove(getUserInput( "Number of cards to move? [X,X]: "));
    command.setDestinyPile(std::to_string(getUserInput("Destiny pile? [1,7]: ")));
}
void views::console::KlondikeCommandGameActionView::visit(WaistToFoundationCommand& command)
{

}
void views::console::KlondikeCommandGameActionView::visit(WaistToStockCommand& command)
{

}
void views::console::KlondikeCommandGameActionView::visit(WaistToTableauCommand& command)
{
    command.setDestinyPile(std::to_string(getUserInput("Destiny pile? [1,7]: ")));
}
unsigned int views::console::KlondikeCommandGameActionView::getUserInput(std::string message)
{
    std::cout << message;
    unsigned int pile = 0;
    std::cin >> pile;
    return pile;
}