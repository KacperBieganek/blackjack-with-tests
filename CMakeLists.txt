cmake_minimum_required(VERSION 3.5)

set(APP_NAME GameApp)

project(${APP_NAME})

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib)
add_subdirectory(DeckLoader)
add_subdirectory(GameCore)


aux_source_directory(. SRC)

add_executable(${APP_NAME} ${SRC})

target_link_libraries(${APP_NAME} GameCoreLib)

add_dependencies(${APP_NAME} RUN_GameCoreTest)