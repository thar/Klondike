#ifndef KLONDIKE_ACTIONLISTCONTROLLERVISITOR_H
#define KLONDIKE_ACTIONLISTCONTROLLERVISITOR_H

namespace controllers
{
    namespace local
    {
        class UserActionListController;
        class AutomaticDeckActionListController;
        class AutomaticCommandActionListController;
    }
    class ActionListControllerVisitor
    {
    public:
        virtual void visit(UserActionListController&) = 0;
        virtual void visit(AutomaticDeckActionListController&) = 0;
        virtual void visit(AutomaticCommandActionListController&) = 0;
    };
}



#endif //KLONDIKE_ACTIONLISTCONTROLLERVISITOR_H
