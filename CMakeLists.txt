cmake_minimum_required(VERSION 3.3)
project(Klondike)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(localization)
add_subdirectory(models)
add_subdirectory(views)
add_subdirectory(controllers)

set(SOURCE_FILES main.cpp Klondike.cpp Klondike.h Logic.h View.h)
add_executable(Klondike ${SOURCE_FILES})
target_link_libraries(Klondike GameLib KlondikeConsoleViewLib localControllersLib localizationLib)
add_custom_command(TARGET Klondike POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/config $<TARGET_FILE_DIR:Klondike>/config)