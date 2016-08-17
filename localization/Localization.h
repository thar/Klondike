#ifndef KLONDIKE_LOCALIZATION_H
#define KLONDIKE_LOCALIZATION_H


#include <string>
#include <map>
#include "LanguajeValue.h"

class Localization
{
public:
    static Localization& getInstance();
    std::string getValue(localization::LanguajeValue);
protected:
private:
    Localization();
    std::map<localization::LanguajeValue, std::string> languajeValuesMap_;
};


#endif //KLONDIKE_LOCALIZATION_H
