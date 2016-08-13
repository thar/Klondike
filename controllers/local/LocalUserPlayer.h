#ifndef KLONDIKE_LOCALUSERPLAYER_H
#define KLONDIKE_LOCALUSERPLAYER_H

#include "LocalPlayerController.h"
#include "../GameActionController.h"
#include "../ConfigurationController.h"

class LocalUserPlayer : public LocalPlayerController
{
public:
    LocalUserPlayer(controllers::GameActionController& gameActionController,
                    controllers::ConfigurationController& configurationController) :
            LocalPlayerController(gameActionController),
            configurationController_(configurationController)
    {
    }

    void accept(PlayerControllerVisitor& playerControllerVisitor)
    {
        playerControllerVisitor.visit(*this);
    }
protected:
private:
    controllers::ConfigurationController& configurationController_;
};


#endif //KLONDIKE_LOCALUSERPLAYER_H
