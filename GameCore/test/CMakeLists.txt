cmake_minimum_required(VERSION 3.1)

set(APP_NAME GameCoreTest)

project(${APP_NAME})

# adding Google Test includes
include_directories(${gmock_SOURCE_DIR}/include)
include_directories(${gtest_SOURCE_DIR}/include)

# adding SUT includes
include_directories(${GameCoreLib_SOURCE_DIR})

aux_source_directory(. SRC)

add_executable(${APP_NAME} ${SRC})

target_link_libraries(${APP_NAME} gmock gmock_main)
target_link_libraries(${APP_NAME} GameCoreLib)

add_custom_target(RUN_${APP_NAME}
                  COMMAND ${APP_NAME}
                  COMMENT "Running " ${APP_NAME})