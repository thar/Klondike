#ifndef KLONDIKE_CONFIGURATIONCONTROLLER_H
#define KLONDIKE_CONFIGURATIONCONTROLLER_H

namespace controllers
{
    namespace local
    {
        class LocalConfigurationController
        {
        public:
            virtual void initDemoPlayer(bool isDemoPlayer) = 0;
            virtual void setExitGame() = 0;
            virtual void setContinueGame() = 0;
        };
    }
}
#endif //KLONDIKE_CONFIGURATIONCONTROLLER_H
