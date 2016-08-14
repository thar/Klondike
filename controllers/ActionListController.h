#ifndef KLONDIKE_ACTIONLISTCONTROLLER_H
#define KLONDIKE_ACTIONLISTCONTROLLER_H

#include <memory>
#include <vector>
#include <string>
#include "ActionListHeader.h"
#include "OperationController.h"
#include "../utils/MenuEntry.h"

namespace controllers
{
    class OperationControllerVisitor;
    class ActionListController : public OperationController
    {
    public:
        virtual std::vector<std::shared_ptr<MenuEntry>>& getActionList() = 0;
        virtual void addAction(std::shared_ptr<MenuEntry> action) = 0;
        virtual void accept(controllers::OperationControllerVisitor& visitor) = 0;
        virtual ActionListHeader& getHeader() = 0;
    protected:
    private:
    };
}


#endif //KLONDIKE_ACTIONLISTCONTROLLER_H
