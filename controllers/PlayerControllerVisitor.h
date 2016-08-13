#ifndef KLONDIKE_PLAYERCONTROLLERVISITOR_H
#define KLONDIKE_PLAYERCONTROLLERVISITOR_H


namespace controllers
{
    namespace local
    {
        class LocalUserPlayer;
        class LocalDemoPlayer;
    }

    class PlayerControllerVisitor
    {
    public:
        virtual void visit(controllers::local::LocalUserPlayer &player) = 0;
        virtual void visit(controllers::local::LocalDemoPlayer &player) = 0;

    protected:
    private:
    };
}


#endif //KLONDIKE_PLAYERCONTROLLERVISITOR_H
