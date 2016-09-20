#ifndef KLONDIKE_OPERATIONCONTROLLERVISITOR_H
#define KLONDIKE_OPERATIONCONTROLLERVISITOR_H


namespace controllers
{
    namespace local
    {
        class UserActionListController;
        class AutomaticDeckActionListController;
        class AutomaticGameActionListController;
        class LocalScoreController;
        class ExitController;
        class AbandonController;
    }
    class OperationControllerVisitor
    {
    public:
        virtual void visit(local::UserActionListController&) = 0;
        virtual void visit(local::AutomaticDeckActionListController&) = 0;
        virtual void visit(local::AutomaticGameActionListController&) = 0;
        virtual void visit(local::LocalScoreController&) = 0;
        //virtual void visit(local::ExitController&) = 0;
        //virtual void visit(local::AbandonController&) = 0;
    };
}


#endif //KLONDIKE_OPERATIONCONTROLLERVISITOR_H
