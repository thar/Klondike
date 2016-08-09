#ifndef KLONDIKE_LOCALPLAYERCONTROLLER_H
#define KLONDIKE_LOCALPLAYERCONTROLLER_H

#include "../PlayerController.h"
#include "../../models/GameDeck.h"
#include "../../models/Game.h"
#include "State.h"
#include "../NewGameController.h"
#include "../ChooseDeckController.h"
#include <stack>

class LocalPlayerController : public PlayerController, KlondikeCommandVisitor
{
public:
    bool isGameFinished()
    {
        return state_ == State::GAME_FINISHED;
    }

    void setLoadGame() { state_ = State::LOAD_GAME; }

    void setNewGame() { state_ = State::IN_GAME; }

    void setDeck(const std::string deckName)
    {
        gameDeck_ = std::make_shared<GameDeck>(deckName);
        game_ = std::make_shared<Game>(*gameDeck_);
    }

    void undoMovement()
    {
        if(!undoStack_.empty())
        {
            redoStack_.push(undoStack_.top());
            undoStack_.pop();
            redoStack_.top()->undo();
        }
    }

    void redoMovement()
    {
        if(!redoStack_.empty())
        {
            undoStack_.push(redoStack_.top());
            redoStack_.pop();
            undoStack_.top()->execute();
        }
    }

    void giveUpGame()
    {
        state_ = State::GAME_FINISHED;
    }

    void saveGame()
    {
        state_ = State::SAVE;
    }
    void executeKlondikeCommand(unsigned int action)
    {
        std::shared_ptr<KlondikeCommand> command = game_->getCommand(action);
        command->accept(*this);
        if (command->validate())
        {
            command->execute();
            clearRedoStack();
            undoStack_.push(command);
        }
    }

protected:

    void clearRedoStack()
    {
        std::stack<std::shared_ptr<KlondikeCommand>> tempStack;
        std::swap(redoStack_, tempStack);
    }

    std::shared_ptr<GameDeck> gameDeck_;
    std::shared_ptr<Game> game_;
    std::stack<std::shared_ptr<KlondikeCommand>> undoStack_;
    std::stack<std::shared_ptr<KlondikeCommand>> redoStack_;
    State state_;
private:
};


#endif //KLONDIKE_LOCALPLAYERCONTROLLER_H
