#include "LocalUndoRedoController.h"
#include "../../models/KlondikeCommandShopBuilder.h"

void controllers::local::LocalUndoRedoController::undo()
{
    if(!undoStack_.empty())
    {
        redoStack_.push_back(undoStack_.back());
        undoStack_.pop_back();
        redoStack_.back()->undo();
    }
}
void controllers::local::LocalUndoRedoController::redo()
{
    if(!redoStack_.empty())
    {
        undoStack_.push_back(redoStack_.back());
        redoStack_.pop_back();
        undoStack_.back()->execute();
    }
}
void controllers::local::LocalUndoRedoController::addCommand(std::shared_ptr<KlondikeCommand> command)
{
    clearRedoStack();
    undoStack_.push_back(command);
}
void controllers::local::LocalUndoRedoController::clearRedoStack()
{
    std::list<std::shared_ptr<KlondikeCommand>> tempStack;
    std::swap(redoStack_, tempStack);
}

void controllers::local::LocalUndoRedoController::saveUndoList(controllers::GameSaver &undoListSaver)
{
    for (auto& movement : undoStack_)
    {
        undoListSaver.addCommand(*movement);
    }
}
