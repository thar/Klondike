#ifndef KLONDIKE_KLONDIKECOMMAND_H
#define KLONDIKE_KLONDIKECOMMAND_H


class KlondikeCommand
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    bool validate()
    {
        valid_ = false;
        __validate();
        return valid_;
    };

protected:
    KlondikeCommand() : valid_(false) {}
    virtual void __validate() = 0;
    bool valid_;
};


#endif //KLONDIKE_KLONDIKECOMMAND_H
