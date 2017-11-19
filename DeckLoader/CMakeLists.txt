cmake_minimum_required(VERSION 3.5)

set(LIB_NAME DeckLoaderLib)

set(CMAKE_CXX_STANDARD 14)

project(${LIB_NAME})

add_subdirectory(Test)

include_directories(${GameCoreLib_SOURCE_DIR})

aux_source_directory(. SRC)

add_library(${LIB_NAME} STATIC ${SRC})


