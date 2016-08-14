#ifndef KLONDIKE_MENUENTRYVISITOR_H
#define KLONDIKE_MENUENTRYVISITOR_H


class KlondikeCommandGameAction;
class UndoGameAction;
class RedoGameAction;
class GiveUpGameAction;
class ExitGameAction;
class DeckAction;


class MenuEntryVisitor
{
public:
    virtual void visit(KlondikeCommandGameAction &action) = 0;
    virtual void visit(UndoGameAction &action) = 0;
    virtual void visit(RedoGameAction &action) = 0;
    virtual void visit(GiveUpGameAction &action) = 0;
    virtual void visit(ExitGameAction &action) = 0;
    virtual void visit(DeckAction &action) = 0;
};


#endif //KLONDIKE_MENUENTRYVISITOR_H
