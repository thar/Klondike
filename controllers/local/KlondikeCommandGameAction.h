#ifndef KLONDIKE_KLONDIKECOMMANDGAMEACTION_H
#define KLONDIKE_KLONDIKECOMMANDGAMEACTION_H

#include <string>
#include <stack>
#include "../../models/KlondikeCommand.h"
#include "MenuEntryVisitor.h"
#include "../../utils/MenuEntry.h"

class KlondikeCommandGameAction : public MenuEntry
{
public:
    KlondikeCommandGameAction(std::string gameActionName, std::shared_ptr<KlondikeCommand> gameCommand,
                    std::stack<std::shared_ptr<KlondikeCommand>> &undoStack,
                    std::stack<std::shared_ptr<KlondikeCommand>> &redoStack) :
            MenuEntry(gameActionName), gameCommandPrototype_(gameCommand), gameCommand_(nullptr),
            undoStack_(undoStack), redoStack_(redoStack)
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
            clearRedoStack();
            undoStack_.push(gameCommand_);
        }
    }
    void accept(MenuEntryVisitor &menuEntryVisitor) { menuEntryVisitor.visit(*this); }
    void accept(KlondikeCommandVisitor& visitor)
    {
        gameCommand_->accept(visitor);
    }

protected:
    void clearRedoStack()
    {
        std::stack<std::shared_ptr<KlondikeCommand>> tempStack;
        std::swap(redoStack_, tempStack);
    }

private:
    std::shared_ptr<KlondikeCommand> gameCommandPrototype_;
    std::shared_ptr<KlondikeCommand> gameCommand_;
    std::stack<std::shared_ptr<KlondikeCommand>> &undoStack_;
    std::stack<std::shared_ptr<KlondikeCommand>> &redoStack_;

};


#endif //KLONDIKE_KLONDIKECOMMANDGAMEACTION_H
