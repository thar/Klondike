
#ifndef KLONDIKE_LOCALUNDOLISTSAVER_H
#define KLONDIKE_LOCALUNDOLISTSAVER_H

#include "../../models/FoundationToTableauCommand.h"
#include "../UndoListSaver.h"
#include <fstream>

namespace controllers
{
    namespace local
    {
        class LocalUndoListSaver : public UndoListSaver, KlondikeCommandSaver
        {
        public:
            LocalUndoListSaver(std::string fileName);
            ~LocalUndoListSaver();
            void addCommand(KlondikeCommand& command);
            void addOrigin(std::string origin);
            void addDestiny(std::string destiny);
            void addNumberOfCards(unsigned int numberOfCards);
        protected:
        private:
            std::ofstream commandListValues_;
        };
    }
}


#endif //KLONDIKE_LOCALUNDOLISTSAVER_H
