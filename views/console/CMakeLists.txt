cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories ("${PROJECT_SOURCE_DIR}/localization")

set(SOURCE_FILES HeaderActionListView.cpp HeaderActionListView.h ActionListView.cpp ActionListView.h ConsoleView.cpp ConsoleView.h KlondikeCommandGameActionView.cpp KlondikeCommandGameActionView.h)
add_library(KlondikeConsoleViewLib ${SOURCE_FILES})