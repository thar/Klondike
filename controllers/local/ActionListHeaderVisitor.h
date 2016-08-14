#ifndef KLONDIKE_ACTIONLISTHEADERVISITOR_H
#define KLONDIKE_ACTIONLISTHEADERVISITOR_H

namespace controllers
{
    namespace local
    {
        class StringActionListHeader;
        //class UserActionListHeader;
        //class GameActionListHeader;
    }
    class ActionListHeaderVisitor
    {
    public:
        virtual void visit(controllers::local::StringActionListHeader&) = 0;
        //virtual void visit(controllers::local::UserActionListHeader&) = 0;
        //virtual void visit(GameActionListHeader&) = 0;
    };
}


#endif //KLONDIKE_ACTIONLISTHEADERVISITOR_H
