#ifndef KLONDIKE_ACTIONLISTCONTROLLER_H
#define KLONDIKE_ACTIONLISTCONTROLLER_H

#include <memory>
#include <vector>
#include <string>
#include "ActionListHeader.h"
#include "OperationController.h"
#include "../utils/MenuEntry.h"

typedef std::vector<std::shared_ptr<MenuEntry>> ActionList;
namespace controllers
{
    class OperationControllerVisitor;
    class ActionListController : public OperationController
    {
    public:
        typedef ActionList::iterator iterator;
        typedef ActionList::const_iterator const_iterator;

        virtual ActionList& getActionList() = 0;
        virtual void addAction(std::shared_ptr<MenuEntry> action) = 0;
        virtual void accept(controllers::OperationControllerVisitor& visitor) = 0;
        virtual ActionListHeader& getHeader() = 0;
        virtual void setHeader(std::shared_ptr<ActionListHeader> header) = 0;

        virtual std::shared_ptr<MenuEntry> getAutomaticAction() = 0;

        virtual iterator begin() = 0;
        virtual iterator end() = 0;
    protected:
    private:
    };
}


#endif //KLONDIKE_ACTIONLISTCONTROLLER_H
