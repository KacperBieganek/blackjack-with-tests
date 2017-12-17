cmake_minimum_required(VERSION 3.1)

set(LIB_NAME GameCoreLib)

project(${LIB_NAME})

add_subdirectory(test)
add_subdirectory(SafeplayerTest)

set(CMAKE_CXX_STANDARD 14)

include_directories(${DeckLoaderLib_SOURCE_DIR})

aux_source_directory(. SRC)

add_library(${LIB_NAME} STATIC ${SRC})