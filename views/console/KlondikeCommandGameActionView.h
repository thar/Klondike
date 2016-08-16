#ifndef KLONDIKE_KLONDIKECOMMANDGAMEACTIONVIEW_H
#define KLONDIKE_KLONDIKECOMMANDGAMEACTIONVIEW_H

#include "../../models/KlondikeCommandVisitor.h"
#include "../../models/FoundationToTableauCommand.h"
#include "../../models/StockToWaistCommand.h"
#include "../../models/TableauToFoundationCommand.h"
#include "../../models/TableauToTableauCommand.h"
#include "../../models/WaistToFoundationCommand.h"
#include "../../models/WaistToStockCommand.h"
#include "../../models/WaistToTableauCommand.h"
#include "../../controllers/local/KlondikeCommandGameAction.h"

class KlondikeCommandGameActionView : public KlondikeCommandVisitor
{
public:
    void interact(controllers::local::KlondikeCommandGameAction &entry)
    {
        entry.accept(*this);
    }
    void visit(FoundationToTableauCommand& command)
    {
        command.setOriginPile(std::to_string(getUserInput("Origin pile? [1,7]: ")));
        command.setCardsToMove(getUserInput( "Number of cards to move? [X,X]: "));
        command.setDestinyPile(std::to_string(getUserInput("Destiny pile? [1,7]: ")));
    }
    void visit(StockToWaistCommand& command)
    {

    }
    void visit(TableauToFoundationCommand& command)
    {
        command.setOriginPile(std::to_string(getUserInput("Origin pile? [1,7]: ")));
    }
    void visit(TableauToTableauCommand& command)
    {
        command.setOriginPile(std::to_string(getUserInput("Origin pile? [1,7]: ")));
        command.setCardsToMove(getUserInput( "Number of cards to move? [X,X]: "));
        command.setDestinyPile(std::to_string(getUserInput("Destiny pile? [1,7]: ")));
    }
    void visit(WaistToFoundationCommand& command)
    {

    }
    void visit(WaistToStockCommand& command)
    {

    }
    void visit(WaistToTableauCommand& command)
    {
        command.setDestinyPile(std::to_string(getUserInput("Destiny pile? [1,7]: ")));
    }
    unsigned int getUserInput(std::string message)
    {
        std::cout << message;
        unsigned int pile = 0;
        std::cin >> pile;
        return pile;
    }
protected:
private:
};


#endif //KLONDIKE_KLONDIKECOMMANDGAMEACTIONVIEW_H
