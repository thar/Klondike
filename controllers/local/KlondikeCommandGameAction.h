#ifndef KLONDIKE_KLONDIKECOMMANDGAMEACTION_H
#define KLONDIKE_KLONDIKECOMMANDGAMEACTION_H

#include <string>
#include <stack>
#include "../../models/KlondikeCommand.h"
#include "MenuEntryVisitor.h"
#include "../../utils/MenuEntry.h"
#include "../UndoRedoController.h"

class KlondikeCommandGameAction : public MenuEntry
{
public:
    KlondikeCommandGameAction(std::string gameActionName, std::shared_ptr<KlondikeCommand> gameCommand,
                              std::shared_ptr<controllers::UndoRedoController> undoRedoController) :
            MenuEntry(gameActionName), gameCommandPrototype_(gameCommand), gameCommand_(nullptr),
            undoRedoController_(undoRedoController)
    {}
    void init()
    {
        gameCommand_ = gameCommandPrototype_->clone();
    }
    void doAction()
    {
        if (gameCommand_->validate())
        {
            gameCommand_->execute();
            undoRedoController_->addCommand(gameCommand_);
        }
    }
    void accept(MenuEntryVisitor &menuEntryVisitor) { menuEntryVisitor.visit(*this); }
    void accept(KlondikeCommandVisitor& visitor)
    {
        gameCommand_->accept(visitor);
    }

protected:
private:
    std::shared_ptr<KlondikeCommand> gameCommandPrototype_;
    std::shared_ptr<KlondikeCommand> gameCommand_;
    std::shared_ptr<controllers::UndoRedoController> undoRedoController_;

};


#endif //KLONDIKE_KLONDIKECOMMANDGAMEACTION_H
