#ifndef KLONDIKE_MENUENTRYVISITOR_H
#define KLONDIKE_MENUENTRYVISITOR_H

namespace controllers
{
    namespace local
    {
        class KlondikeCommandGameAction;
        class UndoGameAction;
        class RedoGameAction;
        class GiveUpGameAction;
        class ExitGameAction;
        class DeckAction;
    }
}

class MenuEntryVisitor
{
public:
    virtual void visit(controllers::local::KlondikeCommandGameAction &action) = 0;
    virtual void visit(controllers::local::UndoGameAction &action) = 0;
    virtual void visit(controllers::local::RedoGameAction &action) = 0;
    virtual void visit(controllers::local::GiveUpGameAction &action) = 0;
    virtual void visit(controllers::local::ExitGameAction &action) = 0;
    virtual void visit(controllers::local::DeckAction &action) = 0;
};



#endif //KLONDIKE_MENUENTRYVISITOR_H
