#ifndef KLONDIKE_UNDOGAMEACTION_H
#define KLONDIKE_UNDOGAMEACTION_H

#include "../../utils/MenuEntry.h"
#include "../../models/KlondikeCommand.h"
#include <memory>
#include <stack>

class UndoGameAction : public MenuEntry
{
public:
    UndoGameAction(std::stack<std::shared_ptr<KlondikeCommand>> &undoStack,
                   std::stack<std::shared_ptr<KlondikeCommand>> &redoStack) :
            MenuEntry("Undo movement"),
            undoStack_(undoStack), redoStack_(redoStack)
    {}

    void doAction()
    {
        if(!undoStack_.empty())
        {
            redoStack_.push(undoStack_.top());
            undoStack_.pop();
            redoStack_.top()->undo();
        }
    }
    void accept(MenuEntryVisitor &menuEntryVisitor) {}

protected:
private:
    std::stack<std::shared_ptr<KlondikeCommand>> &undoStack_;
    std::stack<std::shared_ptr<KlondikeCommand>> &redoStack_;
};


#endif //KLONDIKE_UNDOGAMEACTION_H
