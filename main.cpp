#include <iostream>
#include "models/GameDeck.h"
#include "models/Stock.h"
#include "models/Waist.h"
#include "models/StockToWaistCommand.h"
#include "models/WaistToStockCommand.h"
#include "models/Game.h"

int main() {
    GameDeck spanishDeck("config/decks/spanishDeck.txt");
    GameDeck frenchDeck("config/decks/frenchDeck.txt");

    Pile pile = frenchDeck.getPile();

    Card kingCard = pile.back();
    Card aceCard = pile.front();
    kingCard.turnCard();
    aceCard.turnCard();
    std::cout << kingCard << "] is king? " <<
    (kingCard.isKing() ? std::string("yes") : std::string("no")) << std::endl;
    std::cout << aceCard << "] is king? " <<
    (aceCard.isKing() ? std::string("yes") : std::string("no")) << std::endl;
    std::cout << kingCard << "] is ace? " <<
    (kingCard.isAce() ? std::string("yes") : std::string("no")) << std::endl;
    std::cout << aceCard << "] is ace? " <<
    (aceCard.isAce() ? std::string("yes") : std::string("no")) << std::endl;

    pile.shuffle();
    pile.back().turnCard();
    std::cout << pile << std::endl;

    std::cout << "======================" << std::endl;

    pile = spanishDeck.getPile();
    pile.shuffle();

    Stock stock(pile);
    Waist waist;

    int score = 0;
    StockToWaistCommand command(stock, waist, score);

    command.validate();
    command.execute();

    std::cout << stock << std::endl;
    std::cout << waist << std::endl;

    command.undo();

    std::cout << stock << std::endl;
    std::cout << waist << std::endl;

    while(command.validate())
    {
        command.execute();
        std::cout << stock << std::endl;
        std::cout << waist << std::endl;
    }

    score = 0;
    WaistToStockCommand command2(stock, waist, score);
    if(command2.validate())
    {
        command2.execute();
        std::cout << stock << std::endl;
        std::cout << waist << std::endl;
        command2.undo();
        std::cout << stock << std::endl;
        std::cout << waist << std::endl;
    }

    std::cout << "======================" << std::endl;

    Game game(spanishDeck);
    std::cout << game << std::endl;
    std::shared_ptr<KlondikeCommand> commandAbstract = game.getCommand(0);

    if(commandAbstract->validate())
    {
        commandAbstract->execute();
        std::cout << game << std::endl;
        commandAbstract->undo();
        std::cout << game << std::endl;
    }


    if (commandAbstract->validate())
    {
        commandAbstract->execute();
        std::cout << game << std::endl;
        commandAbstract = game.getCommand(2);
        if (commandAbstract->validate())
        {
            commandAbstract->execute();
            std::cout << game << std::endl;
            commandAbstract->undo();
            std::cout << game << std::endl;
        }
        else
        {
            std::cout << "invalid movement" << std::endl;
        }
    }


    return 0;
}