#include "LocalUndoRedoController.h"

void controllers::local::LocalUndoRedoController::undo()
{
    if(!undoStack_.empty())
    {
        redoStack_.push(undoStack_.top());
        undoStack_.pop();
        redoStack_.top()->undo();
    }
}
void controllers::local::LocalUndoRedoController::redo()
{
    if(!redoStack_.empty())
    {
        undoStack_.push(redoStack_.top());
        redoStack_.pop();
        undoStack_.top()->execute();
    }
}
void controllers::local::LocalUndoRedoController::addCommand(std::shared_ptr<KlondikeCommand> command)
{
    clearRedoStack();
    undoStack_.push(command);
}
void controllers::local::LocalUndoRedoController::clearRedoStack()
{
    std::stack<std::shared_ptr<KlondikeCommand>> tempStack;
    std::swap(redoStack_, tempStack);
}