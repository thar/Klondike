#ifndef KLONDIKE_GAMEACTIONVISITOR_H
#define KLONDIKE_GAMEACTIONVISITOR_H

class KlondikeCommandGameAction;
class UndoGameAction;
class RedoGameAction;
class GiveUpGameAction;
class ExitGameAction;


class GameActionVisitor
{
public:
    virtual void visit(KlondikeCommandGameAction &action) = 0;
    virtual void visit(UndoGameAction &action) = 0;
    virtual void visit(RedoGameAction &action) = 0;
    virtual void visit(GiveUpGameAction &action) = 0;
    virtual void visit(ExitGameAction &action) = 0;
};


#endif //KLONDIKE_GAMEACTIONVISITOR_H
