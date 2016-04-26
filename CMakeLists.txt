cmake_minimum_required(VERSION 3.3)
project(Klondike)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp models/Pile.cpp models/Pile.h models/Card.cpp models/Card.h models/Value.h models/Suit.h models/CardProperty.h models/CardProperty.cpp models/Game.cpp models/Game.h models/Waist.cpp models/Waist.h models/Stock.cpp models/Stock.h models/Foundation.cpp models/Foundation.h models/Tableau.cpp models/Tableau.h models/PilesGroup.cpp models/PilesGroup.h models/KlondikeCommand.h models/StockToWaistCommand.cpp models/StockToWaistCommand.h models/GameDeck.cpp models/GameDeck.h models/WaistToStockCommand.cpp models/WaistToStockCommand.h models/KlondikeCommandShop.cpp models/KlondikeCommandShop.h models/GameBoard.cpp models/GameBoard.h models/KlondikeCommandShopBuilder.cpp models/KlondikeCommandShopBuilder.h models/WaistToFoundationCommand.cpp models/WaistToFoundationCommand.h)
add_executable(Klondike ${SOURCE_FILES})
add_custom_command(TARGET Klondike POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/config $<TARGET_FILE_DIR:Klondike>/config)