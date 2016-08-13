#ifndef KLONDIKE_REDOGAMEACTION_H
#define KLONDIKE_REDOGAMEACTION_H

#include "../../utils/MenuEntry.h"
#include "../../models/KlondikeCommand.h"
#include <memory>
#include <stack>

class RedoGameAction : public MenuEntry
{
public:
    RedoGameAction(std::stack<std::shared_ptr<KlondikeCommand>> &undoStack,
    std::stack<std::shared_ptr<KlondikeCommand>> &redoStack) :
            MenuEntry("Redo movement"),
    undoStack_(undoStack), redoStack_(redoStack)
    {}

    void doAction()
    {
        if(!redoStack_.empty())
        {
            undoStack_.push(redoStack_.top());
            redoStack_.pop();
            undoStack_.top()->execute();
        }
    }
    void accept(MenuEntryVisitor &menuEntryVisitor) {}

protected:
private:
    std::stack<std::shared_ptr<KlondikeCommand>> &undoStack_;
    std::stack<std::shared_ptr<KlondikeCommand>> &redoStack_;
};


#endif //KLONDIKE_REDOGAMEACTION_H
