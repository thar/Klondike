#ifndef KLONDIKE_AUTOMATICACTIONLISTCONTROLLER_H
#define KLONDIKE_AUTOMATICACTIONLISTCONTROLLER_H

#include <memory>
#include "ActionListController.h"
#include "../utils/MenuEntry.h"

namespace controllers
{
    class AutomaticActionListController : public ActionListController
    {
    public:
        virtual std::shared_ptr<MenuEntry> getAction() = 0;
    protected:
    private:
    };
}

#endif //KLONDIKE_AUTOMATICACTIONLISTCONTROLLER_H
