#ifndef KLONDIKE_HEADERACTIONLISTVIEW_H
#define KLONDIKE_HEADERACTIONLISTVIEW_H

#include "../../controllers/local/ActionListHeaderVisitor.h"
#include "../../controllers/ActionListHeader.h"
#include "../../controllers/local/StringActionListHeader.h"

namespace views
{
    namespace console
    {
        class HeaderActionListView : public controllers::ActionListHeaderVisitor
        {
        public:
            void show(controllers::ActionListHeader& header);
            void visit(controllers::local::StringActionListHeader & header);
            //void visit(StringActionListHeader& header);
        protected:
        private:
        };
    }
}


#endif //KLONDIKE_HEADERACTIONLISTVIEW_H
