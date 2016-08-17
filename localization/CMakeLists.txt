cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Localization.cpp Localization.h LanguajeValue.h)
add_library(localizationLib ${SOURCE_FILES})