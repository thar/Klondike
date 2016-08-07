#ifndef KLONDIKE_LOCALOPERATIONCONTROLLER_H
#define KLONDIKE_LOCALOPERATIONCONTROLLER_H

#include "../OperationController.h"

namespace controllers
{
    namespace local
    {
        class LocalOperationController : public controllers::OperationController
        {
        public:
            void accept(OperationControllerVisitor& operationControllerVisitor);

        protected:
        private:
        };
    }
}


#endif //KLONDIKE_LOCALOPERATIONCONTROLLER_H
