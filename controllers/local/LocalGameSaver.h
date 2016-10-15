
#ifndef KLONDIKE_LOCALUNDOLISTSAVER_H
#define KLONDIKE_LOCALUNDOLISTSAVER_H

#include "../../models/FoundationToTableauCommand.h"
#include "../GameSaver.h"
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <cereal/archives/json.hpp>
#include <fstream>

namespace controllers
{
    namespace local
    {
        class LocalGameSaver : public GameSaver, KlondikeCommandSaver
        {
        public:
            LocalGameSaver(std::string fileName);
            ~LocalGameSaver()
            {
                std::ofstream outputstream(fileName_, std::ofstream::out);
                {
                    cereal::JSONOutputArchive output(outputstream);
                    output(cereal::make_nvp("gameData", *this));
                }
                outputstream.close();
            }
            void addRandomSeed(unsigned int seed);
            void addDeckPath(std::string deckPath);
            void addCommand(KlondikeCommand& command);
            void addOrigin(std::string origin);
            void addDestiny(std::string destiny);
            void addNumberOfCards(unsigned int numberOfCards);
            unsigned int getRandomSeed();
            std::string getDeckPath();
            void restoreCommands(Game& game);
            void load()
            {
                std::ifstream inputstream(fileName_);
                {
                    cereal::JSONInputArchive input(inputstream);
                    input(*this);
                }
                inputstream.close();
            }

            template<class Archive>
            void serialize(Archive & archive)
            {
                archive(CEREAL_NVP(deckFilePath_), CEREAL_NVP(seed_), CEREAL_NVP(commandList_));
            }
        protected:
        private:
            friend class cereal::access;
            struct CommandValues
            {
                unsigned int index;
                std::string origin;
                std::string destiny;
                unsigned int numberOfCards;

                template<class Archive>
                void serialize(Archive & archive)
                {
                    archive(CEREAL_NVP(index), CEREAL_NVP(origin), CEREAL_NVP(destiny), CEREAL_NVP(numberOfCards));
                }
            };
            std::vector<CommandValues> commandList_;
            std::string fileName_;
            std::string deckFilePath_;
            unsigned int seed_;
        };
    }
}


#endif //KLONDIKE_LOCALUNDOLISTSAVER_H
