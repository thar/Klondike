cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories ("${PROJECT_SOURCE_DIR}/localization" "${PROJECT_SOURCE_DIR}/libs/cereal/include")

set(SOURCE_FILES LocalLogic.cpp LocalLogic.h UndoGameAction.cpp UndoGameAction.h RedoGameAction.cpp RedoGameAction.h GiveUpGameAction.cpp GiveUpGameAction.h ExitGameAction.cpp ExitGameAction.h PlayerChooseControllerBuilder.cpp PlayerChooseControllerBuilder.h DeckControllerBuilder.cpp DeckControllerBuilder.h UserActionListController.cpp UserActionListController.h AutomaticDeckActionListController.cpp AutomaticDeckActionListController.h PlayerAction.cpp PlayerAction.h DeckAction.cpp DeckAction.h StringActionListHeader.h StringActionListHeader.cpp GameActionListHeader.cpp GameActionListHeader.h GameActionsControllerBuilder.cpp GameActionsControllerBuilder.h LocalUndoRedoController.cpp LocalUndoRedoController.h AutomaticGameActionListController.cpp AutomaticGameActionListController.h LocalActionListController.cpp LocalActionListController.h KlondikeCommandGameAction.cpp LocalScoreController.cpp LocalScoreController.h SaveGameAction.cpp SaveGameAction.h LocalGameSaver.cpp LocalGameSaver.h NewGameAction.cpp NewGameAction.h LoadGameAction.cpp LoadGameAction.h ExitControllerBuilder.cpp ExitControllerBuilder.h StartGameControllerBuilder.cpp StartGameControllerBuilder.h LoadGameControllerBuilder.cpp LoadGameControllerBuilder.h GameFromFileAction.cpp GameFromFileAction.h)
add_library(localControllersLib ${SOURCE_FILES})
target_link_libraries(localControllersLib GameLib)