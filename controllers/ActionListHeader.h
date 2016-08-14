#ifndef KLONDIKE_ACTIONLISTHEADER_H
#define KLONDIKE_ACTIONLISTHEADER_H

namespace controllers
{
    class ActionListHeaderVisitor;
    class ActionListHeader
    {
    public:
        virtual void accept(controllers::ActionListHeaderVisitor& visitor) = 0;
    protected:
    private:
    };
}


#endif //KLONDIKE_ACTIONLISTHEADER_H
