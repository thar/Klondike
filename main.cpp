#include <iostream>
#include "models/GameDeck.h"
#include "models/Stock.h"
#include "models/StockToWaistCommand.h"
#include "models/Game.h"

unsigned int showMenu()
{
    unsigned int option = 1;
    do
    {
        if (0 >= option || 12 < option)
            std::cout << "Please, chose an option in range" << std::endl;
        std::cout << "1. Move from Waist to Stock" << std::endl;
        std::cout << "2. Move from Stock to Waist" << std::endl;
        std::cout << "3. Move from Waist to Foundation" << std::endl;
        std::cout << "4. Move from Waist to Tableau" << std::endl;
        std::cout << "5. Move from Tableau to Foundation" << std::endl;
        std::cout << "6. Move from Tableau to Tableau" << std::endl;
        std::cout << "7. Move from Foundation to Tableau" << std::endl;
        std::cout << "8. Undo movement" << std::endl;
        std::cout << "9. Redo movement" << std::endl;
        std::cout << "10. Save game" << std::endl;
        std::cout << "11. Give up game" << std::endl;
        std::cout << "12. Exit" << std::endl;
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Option? [1-12]: ";
        std::cin >> option;
    } while (0 >= option || 12 < option);
    return option;
}

int main() {
    GameDeck spanishDeck("config/decks/spanishDeck.txt");
    GameDeck frenchDeck("config/decks/frenchDeck.txt");

    /*
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

    Game game1(spanishDeck);
    std::cout << game1 << std::endl;
    std::shared_ptr<KlondikeCommand> commandAbstract = game1.getCommand(0);

    if(commandAbstract->validate())
    {
        commandAbstract->execute();
        std::cout << game1 << std::endl;
        commandAbstract->undo();
        std::cout << game1 << std::endl;
    }


    if (commandAbstract->validate())
    {
        commandAbstract->execute();
        std::cout << game1 << std::endl;
        commandAbstract = game1.getCommand(2);
        if (commandAbstract->validate())
        {
            commandAbstract->execute();
            std::cout << game1 << std::endl;
            commandAbstract->undo();
            std::cout << game1 << std::endl;
        }
        else
        {
            std::cout << "invalid movement" << std::endl;
        }
    }
    */

    Game game(spanishDeck);
    std::shared_ptr<KlondikeCommand> gameCommand;
    unsigned int option = 0;
    while (12 != option)
    {
        std::cout << game << std::endl;
        option = showMenu();
        if (8 > option)
        {
            gameCommand = game.getCommand(option - 1);
            if (4 == option)
            {
                std::cout << "Destiny pile? [1,7]: ";
                unsigned int destiny = 0;
                std::cin >> destiny;
                gameCommand->setDestinyPile(std::to_string(destiny));
            }
            else if (5 == option)
            {
                std::cout << "Origin pile? [1,7]: ";
                unsigned int origin = 0;
                std::cin >> origin;
                gameCommand->setOriginPile(std::to_string(origin));
            }
            else if (6 == option)
            {
                std::cout << "Origin pile? [1,7]: ";
                unsigned int origin = 0;
                std::cin >> origin;
                gameCommand->setOriginPile(std::to_string(origin));
                std::cout << "Number of cards to move? [X,X]: ";
                unsigned int numberOfCards = 0;
                std::cin >> numberOfCards;
                gameCommand->setCardsToMove(numberOfCards);
                std::cout << "Destiny pile? [1,7]: ";
                unsigned int destiny = 0;
                std::cin >> destiny;
                gameCommand->setDestinyPile(std::to_string(destiny));
            }
            else if (7 == option)
            {
                std::cout << "Origin pile? [1,7]: ";
                std::string origin = 0;
                std::cin >> origin;
                gameCommand->setOriginPile(origin);
                std::cout << "Number of cards to move? [X,X]: ";
                unsigned int numberOfCards = 0;
                std::cin >> numberOfCards;
                gameCommand->setCardsToMove(numberOfCards);
                std::cout << "Destiny pile? [1,7]: ";
                unsigned int destiny = 0;
                std::cin >> destiny;
                gameCommand->setDestinyPile(std::to_string(destiny));
            }
            if (gameCommand->validate())
            {
                gameCommand->execute();
            }
            else
            {
                std::cout << "invalid movement" << std::endl;
            }
        }
        else if (8 == option)
        {
            gameCommand->undo();
        }
        else if (9 == option)
        {
            if (gameCommand->validate())
            {
                gameCommand->execute();
            }
        }
    }

    return 0;
}