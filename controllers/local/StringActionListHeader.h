#ifndef KLONDIKE_DECKACTIONLISTHEADER_H
#define KLONDIKE_DECKACTIONLISTHEADER_H

#include <string>
#include "../ActionListHeader.h"
#include "ActionListHeaderVisitor.h"

namespace controllers
{
    namespace local
    {
        class StringActionListHeader : public ActionListHeader
        {
        public:
            StringActionListHeader(std::string menuHeader);
            void accept(controllers::ActionListHeaderVisitor& visitor);
            std::string getMenuHeader();
        protected:
        private:
            std::string menuHeader_;
        };
    }
}


#endif //KLONDIKE_DECKACTIONLISTHEADER_H
