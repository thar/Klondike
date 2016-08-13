#ifndef KLONDIKE_PLAYERINTERACTIONVIEW_H
#define KLONDIKE_PLAYERINTERACTIONVIEW_H

#include <iostream>
#include "../../controllers/PlayerControllerVisitor.h"
#include "../../controllers/local/MenuEntryVisitor.h"
#include "../../controllers/local/LocalDemoPlayer.h"
#include "../../controllers/local/LocalUserPlayer.h"

namespace views
{
    namespace console
    {
        class PlayerInteractionView : public PlayerControllerVisitor, public MenuEntryVisitor
        {
        public:
            void interact(PlayerController &player)
            {
                player_ = &player;
                player.accept(*this);
            }

            void visit(LocalDemoPlayer& player)
            {
                getMenuEntriesPtr(player);
                showMenuHeader();
                printMenu();
                std::shared_ptr<MenuEntry> entry = getAutomaticInput(player);
                std::cout << "Demo player chooses: " << entry->getName() << std::endl;
                entry->doAction();
            }

            void visit(LocalUserPlayer& player)
            {
                getMenuEntriesPtr(player);
                showMenuHeader();
                std::shared_ptr<MenuEntry> entry = getUserInput();
                entry->accept(*this);
                entry->doAction();
            }

        protected:
            virtual void showMenuHeader() {};
            virtual void getMenuEntriesPtr(LocalPlayerController& player) = 0;
            virtual std::shared_ptr<MenuEntry> getAutomaticInput(LocalDemoPlayer& player) = 0;
            PlayerController* player_;
            std::vector<std::shared_ptr<MenuEntry>> *entries_;

        private:
            void printMenu()
            {
                unsigned int optionIndex = 0;
                for (auto &it : *entries_)
                {
                    std::cout << ++optionIndex << ". " << it->getName() << std::endl;
                }
                std::cout << "----------------------------------" << std::endl;
            }
            std::shared_ptr<MenuEntry> getUserInput()
            {
                unsigned int option = 1;
                do
                {
                    if (0 >= option || entries_->size() < option)
                        std::cout << "Please, chose an option in range" << std::endl;
                    printMenu();
                    std::cout << "Option? [1-" << entries_->size() << "]: " << std::endl;
                    std::cin >> option;
                } while (0 >= option || entries_->size() < option);
                return entries_->at(option - 1);
            }
        };
    }
}

#endif //KLONDIKE_PLAYERINTERACTIONVIEW_H
