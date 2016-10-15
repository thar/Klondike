#ifndef KLONDIKE_KLONDIKECOMMAND_H
#define KLONDIKE_KLONDIKECOMMAND_H

#include "PilesGroup.h"
#include "KlondikeCommandVisitor.h"
#include "KlondikeCommandSaver.h"
#include <memory>

class KlondikeCommand
{
public:
    virtual void __execute() = 0;
    virtual void __undo() = 0;
    void execute()
    {
        __execute();
        score_ += movementScore_;
    };
    void undo()
    {
        __undo();
        score_ -= movementScore_;
    };
    virtual void accept(KlondikeCommandVisitor& visitor) = 0;
    bool validate()
    {
        valid_ = false;
        __validate();
        return valid_;
    };
    virtual std::shared_ptr<KlondikeCommand> clone() = 0;

    virtual std::set<std::string> getOriginPiles() = 0;
    virtual std::set<std::string> getDestinyPiles() = 0;

    void setOriginPile(std::string originPile)
    { originPile_ = originPile; }

    void setDestinyPile(std::string destinyPile)
    { destinyPile_ = destinyPile; }

    void setCardsToMove(unsigned int cardsToMove)
    { cardsToMove_ = cardsToMove; }

    void save(KlondikeCommandSaver& saver)
    {
        saver.addOrigin(originPile_);
        saver.addDestiny(destinyPile_);
        saver.addNumberOfCards(cardsToMove_);
    }

protected:
    KlondikeCommand(int &score, int movementScore)
            : valid_(false), score_(score), cardsToMove_(0),
              movementScore_(movementScore)
    {}
    virtual void __validate() = 0;

    bool valid_;
    int& score_;
    unsigned int cardsToMove_;
    const int movementScore_;
    std::string originPile_;
    std::string destinyPile_;
    static int turnOverScore;
};


#endif //KLONDIKE_KLONDIKECOMMAND_H
