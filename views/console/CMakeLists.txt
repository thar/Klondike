include_directories ("${PROJECT_SOURCE_DIR}/localization")

set(SOURCE_FILES HeaderActionListView.cpp HeaderActionListView.h ActionListView.cpp ActionListView.h ConsoleView.cpp ConsoleView.h KlondikeCommandGameActionView.cpp KlondikeCommandGameActionView.h ScoreView.cpp ScoreView.h)
add_library(KlondikeConsoleViewLib ${SOURCE_FILES})