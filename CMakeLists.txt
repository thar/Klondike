cmake_minimum_required(VERSION 3.3)
project(Klondike)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp  models/Pile.cpp models/Pile.h models/Card.cpp models/Card.h models/Value.h models/Suit.h models/DeckFactory.h models/SpanishDeckBuilder.h models/FrenchDeckBuilder.h models/CardProperty.h models/DeckBuilder.h models/SpanishSuit.h models/FrenchSuit.h models/SpanishDeckBuilder.cpp models/FrenchDeckBuilder.cpp models/FactoryClassTemplate.h models/CardProperty.cpp)
add_executable(Klondike ${SOURCE_FILES})