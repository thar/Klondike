#ifndef KLONDIKE_PLAYERCONTROLLERVISITOR_H
#define KLONDIKE_PLAYERCONTROLLERVISITOR_H

class LocalUserPlayer;
class LocalDemoPlayer;

class PlayerControllerVisitor
{
public:
    virtual void visit(LocalUserPlayer& player) = 0;
    virtual void visit(LocalDemoPlayer& player) = 0;
protected:
private:
};


#endif //KLONDIKE_PLAYERCONTROLLERVISITOR_H
