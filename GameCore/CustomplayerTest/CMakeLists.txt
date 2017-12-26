cmake_minimum_required(VERSION 3.5)

set(APP_NAME CustomplayerTests)

project(${APP_NAME})

# adding Google Test includes
include_directories(${gmock_SOURCE_DIR}/include)
include_directories(${gtest_SOURCE_DIR}/include)



aux_source_directory(. SRC)

add_executable(${APP_NAME} ${SRC})

target_link_libraries(${APP_NAME} gmock gmock_main)
target_link_libraries(${APP_NAME} GameCoreLib)

