cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories ("${PROJECT_SOURCE_DIR}/localization")

set(SOURCE_FILES Pile.cpp Pile.h Card.cpp Card.h Value.h Suit.h CardProperty.h CardProperty.cpp Game.cpp Game.h Waste.cpp Waste.h Stock.cpp Stock.h Foundation.cpp Foundation.h Tableau.cpp Tableau.h PilesGroup.cpp PilesGroup.h KlondikeCommand.h StockToWasteCommand.cpp StockToWasteCommand.h GameDeck.cpp GameDeck.h WasteToStockCommand.cpp WasteToStockCommand.h KlondikeCommandShop.cpp KlondikeCommandShop.h GameBoard.cpp GameBoard.h KlondikeCommandShopBuilder.cpp KlondikeCommandShopBuilder.h WasteToFoundationCommand.cpp WasteToFoundationCommand.h WasteToTableauCommand.cpp WasteToTableauCommand.h TableauToFoundationCommand.cpp TableauToFoundationCommand.h TableauToTableauCommand.cpp TableauToTableauCommand.h FoundationToTableauCommand.cpp FoundationToTableauCommand.h KlondikeCommandVisitor.h KlondikeCommandSaver.h KlondikeCommand.cpp)
add_library(GameLib ${SOURCE_FILES})