#ifndef KLONDIKE_GAMEACTIONSINITIALIZER_H
#define KLONDIKE_GAMEACTIONSINITIALIZER_H

#include "LocalDemoPlayer.h"
#include "LocalUserPlayer.h"
#include "../ConfigurationController.h"
#include "KlondikeCommandGameAction.h"
#include "UndoGameAction.h"
#include "RedoGameAction.h"
#include "GiveUpGameAction.h"
#include "ExitGameAction.h"

class GameActionsInitializer : public PlayerControllerVisitor
{
public:
    GameActionsInitializer(PlayerController& playerController, Game& game, controllers::ConfigurationController& configurationController) : playerController_(playerController),
                                                                             game_(game), configurationController_(configurationController)
    {
        playerController_.accept(*this);
    }

    void visit(LocalUserPlayer& player)
    {
        addKlondikeCommandGameActions(player);

        player.addGameAction(std::make_shared<UndoGameAction>(player.getUndoStack(), player.getRedoStack()));
        player.addGameAction(std::make_shared<RedoGameAction>(player.getUndoStack(), player.getRedoStack()));

        player.addGameAction(std::make_shared<GiveUpGameAction>(configurationController_));
        player.addGameAction(std::make_shared<ExitGameAction>(configurationController_));
    }

    void visit(LocalDemoPlayer& player)
    {
        addKlondikeCommandGameActions(player);
    }

    void addKlondikeCommandGameActions(LocalPlayerController& player)
    {
        player.addGameAction(std::make_shared<KlondikeCommandGameAction>("Move from Stock to Waist", game_.getCommand(0), player.getUndoStack(), player.getRedoStack()));
        player.addGameAction(std::make_shared<KlondikeCommandGameAction>("Move from Waist to Stock", game_.getCommand(1), player.getUndoStack(), player.getRedoStack()));
        player.addGameAction(std::make_shared<KlondikeCommandGameAction>("Move from Waist to Foundation", game_.getCommand(2), player.getUndoStack(), player.getRedoStack()));
        player.addGameAction(std::make_shared<KlondikeCommandGameAction>("Move from Waist to Tableau", game_.getCommand(3), player.getUndoStack(), player.getRedoStack()));
        player.addGameAction(std::make_shared<KlondikeCommandGameAction>("Move from Tableau to Foundation", game_.getCommand(4), player.getUndoStack(), player.getRedoStack()));
        player.addGameAction(std::make_shared<KlondikeCommandGameAction>("Move from Tableau to Tableau", game_.getCommand(5), player.getUndoStack(), player.getRedoStack()));
        player.addGameAction(std::make_shared<KlondikeCommandGameAction>("Move from Foundation to Tableau", game_.getCommand(6), player.getUndoStack(), player.getRedoStack()));
    }
protected:
private:
    PlayerController& playerController_;
    Game& game_;
    controllers::ConfigurationController& configurationController_;
};


#endif //KLONDIKE_GAMEACTIONSINITIALIZER_H
