#include "KlondikeCommandGameActionView.h"
#include "Localization.h"
#include <iostream>

void views::console::KlondikeCommandGameActionView::interact(controllers::local::KlondikeCommandGameAction &entry)
{
    entry.accept(*this);
}
void views::console::KlondikeCommandGameActionView::visit(FoundationToTableauCommand& command)
{
    command.setOriginPile(getOptionsInput(Localization::getInstance().getValue(localization::ORIGIN_PILE), command.getOriginPiles()));
    command.setDestinyPile((getOptionsInput(Localization::getInstance().getValue(localization::DESTINY_PILE), command.getDestinyPiles())));
}
void views::console::KlondikeCommandGameActionView::visit(StockToWaistCommand& command)
{

}
void views::console::KlondikeCommandGameActionView::visit(TableauToFoundationCommand& command)
{
    command.setOriginPile(getOptionsInput(Localization::getInstance().getValue(localization::ORIGIN_PILE), command.getOriginPiles()));
}
void views::console::KlondikeCommandGameActionView::visit(TableauToTableauCommand& command)
{
    command.setOriginPile(getOptionsInput(Localization::getInstance().getValue(localization::ORIGIN_PILE), command.getOriginPiles()));
    command.setCardsToMove(getUserInput( Localization::getInstance().getValue(localization::NUMBER_OF_CARDS) + ": "));
    command.setDestinyPile((getOptionsInput(Localization::getInstance().getValue(localization::DESTINY_PILE), command.getDestinyPiles())));
}
void views::console::KlondikeCommandGameActionView::visit(WaistToFoundationCommand& command)
{

}
void views::console::KlondikeCommandGameActionView::visit(WaistToStockCommand& command)
{

}
void views::console::KlondikeCommandGameActionView::visit(WaistToTableauCommand& command)
{
    command.setDestinyPile((getOptionsInput(Localization::getInstance().getValue(localization::DESTINY_PILE), command.getDestinyPiles())));
}
unsigned int views::console::KlondikeCommandGameActionView::getUserInput(std::string message)
{
    std::cout << message;
    unsigned int pile = 0;
    std::cin >> pile;
    return pile;
}

std::string
views::console::KlondikeCommandGameActionView::getOptionsInput(std::string message, std::set<std::string> options)
{
    std::string pile;
    do
    {
        std::cout << message << "? [";
        for (const auto& option : options)
        {
            std::cout << option << ",";
        }
        std::cout << "]:" << std::endl;
        std::cin >> pile;
    } while (options.find(pile) == options.end());
    return pile;
}
