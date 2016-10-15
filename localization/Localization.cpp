#include "Localization.h"

Localization& Localization::getInstance()
{
    static Localization localization = Localization();
    return localization;
}
std::string Localization::getValue(localization::LanguajeValue value)
{
    return languajeValuesMap_[value];
}
Localization::Localization()
{
    using namespace localization;
    languajeValuesMap_[SELECT] = "Select";
    languajeValuesMap_[PLAYER] = "player";
    languajeValuesMap_[USER] = "User";
    languajeValuesMap_[DEMO] = "Demo";
    languajeValuesMap_[DECK] = "Deck";
    languajeValuesMap_[OPTION] = "Option";
    languajeValuesMap_[STOCK] = "Stock";
    languajeValuesMap_[WAIST] = "Waist";
    languajeValuesMap_[FOUNDATION] = "Fountadion";
    languajeValuesMap_[TABLEAU] = "Tableau";
    languajeValuesMap_[MOVE_FROM] = "Move from";
    languajeValuesMap_[MOVE_TO] = "to";
    languajeValuesMap_[UNDO_MOVEMENT] = "Undo movement";
    languajeValuesMap_[REDO_MOVEMENT] = "Redo movement";
    languajeValuesMap_[GIVE_UP_GAME] = "Give up game";
    languajeValuesMap_[EXIT_GAME] = "Exit game";
    languajeValuesMap_[SAVE_GAME] = "Save game";
    languajeValuesMap_[NUMBER_OF_CARDS] = "Number of cards";
    languajeValuesMap_[ORIGIN_PILE] = "Origin pile";
    languajeValuesMap_[DESTINY_PILE] = "Destiny pile";
    languajeValuesMap_[SELECTED_ACTION] = "Selected action";
    languajeValuesMap_[OPTION_IN_RANGE] = "Please, chose an option in range";
    languajeValuesMap_[FILE_NAME] = "Enter file name";
    languajeValuesMap_[FILE_EXISTS] = "File exists. What do you want to do?";
    languajeValuesMap_[NEW_FILE_NAME] = "Enter new name";
    languajeValuesMap_[FILE_OVERWRITE] = "Overwrite";
    languajeValuesMap_[CHOOSE_FILE] = "Choose file";
    languajeValuesMap_[NEW_GAME] = "New game";
    languajeValuesMap_[LOAD_GAME] = "Load game";
    languajeValuesMap_[SPANISH] = "Spanish";
    languajeValuesMap_[FRENCH] = "French";
    languajeValuesMap_[TOP_SCORE] = "Top scores";
    languajeValuesMap_[SCORE] = "Score";
}