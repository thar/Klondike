#ifndef KLONDIKE_DECKSELECTIONVIEW_H
#define KLONDIKE_DECKSELECTIONVIEW_H

#include "ActionListView.h"
#include "KlondikeCommandGameActionView.h"
#include "../../controllers/local/KlondikeCommandGameAction.h"

namespace views
{
    namespace console
    {
        class DeckSelectionView : public ActionListView
        {
        public:
            void visit(KlondikeCommandGameAction &entry)
            {
                entry.init();
                KlondikeCommandGameActionView().interact(entry);
            }
            void visit(UndoGameAction &entry) {}
            void visit(RedoGameAction &entry) {}
            void visit(GiveUpGameAction &entry) {}
            void visit(ExitGameAction &entry) {}
            void visit(DeckAction &entry) {}
        protected:
        private:
        };
    }
}

#endif //KLONDIKE_DECKSELECTIONVIEW_H
