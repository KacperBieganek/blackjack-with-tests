cmake_minimum_required(VERSION 3.5)

set(APP_NAME DeckLoaderTest)

project(${APP_NAME})

set(CMAKE_CXX_STANDARD 14)

include_directories(${gmock_SOURCE_DIR}/include)
include_directories(${gtest_SOURCE_DIR}/include)

include_directories(${DeckLoaderLib_SOURCE_DIR})

aux_source_directory(. SRC)

add_executable(${APP_NAME} ${SRC})

target_link_libraries(${APP_NAME} gmock gmock_main)
target_link_libraries(${APP_NAME} DeckLoaderLib)