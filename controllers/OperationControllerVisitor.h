#ifndef KLONDIKE_OPERATIONCONTROLLERVISITOR_H
#define KLONDIKE_OPERATIONCONTROLLERVISITOR_H


namespace controllers
{
    class PlayerSeleccionController;
    class ExitGameController;

    class OperationControllerVisitor
    {
    public:
        virtual void visit(PlayerSeleccionController &playerSeleccionController) = 0;
        virtual void visit(ExitGameController &playerSeleccionController) = 0;

    protected:
    private:
    };
}


#endif //KLONDIKE_OPERATIONCONTROLLERVISITOR_H
