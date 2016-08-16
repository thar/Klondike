#include "KlondikeCommandGameAction.h"

controllers::local::KlondikeCommandGameAction::KlondikeCommandGameAction(std::string gameActionName, std::shared_ptr<KlondikeCommand> gameCommand,
        std::shared_ptr<controllers::UndoRedoController> undoRedoController) :
MenuEntry(gameActionName), gameCommandPrototype_(gameCommand), gameCommand_(nullptr),
undoRedoController_(undoRedoController)
{}
void controllers::local::KlondikeCommandGameAction::init()
{
    gameCommand_ = gameCommandPrototype_->clone();
}
void controllers::local::KlondikeCommandGameAction::doAction()
{
    if (gameCommand_->validate())
    {
        gameCommand_->execute();
        undoRedoController_->addCommand(gameCommand_);
    }
}
void controllers::local::KlondikeCommandGameAction::accept(MenuEntryVisitor &menuEntryVisitor)
{
    menuEntryVisitor.visit(*this);
}
void controllers::local::KlondikeCommandGameAction::accept(KlondikeCommandVisitor& visitor)
{
    gameCommand_->accept(visitor);
}
