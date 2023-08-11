cmake_minimum_required(VERSION 3.0...3.26)

project(bfs-rogue
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

set(CMAKE_BINARY_DIR "./build")

set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/config.h
    ${PROJECT_SOURCE_DIR}/src/view/view.cpp
    ${PROJECT_SOURCE_DIR}/src/view/view.h
    ${PROJECT_SOURCE_DIR}/src/model/model.cpp
    ${PROJECT_SOURCE_DIR}/src/model/model.h
    ${PROJECT_SOURCE_DIR}/src/model/point/point.h
    ${PROJECT_SOURCE_DIR}/src/model/bfs/bfs.h
    ${PROJECT_SOURCE_DIR}/src/model/game_level/game_level.cpp
    ${PROJECT_SOURCE_DIR}/src/model/game_level/game_level.h
    ${PROJECT_SOURCE_DIR}/src/model/game_level/tile_types.h
    ${PROJECT_SOURCE_DIR}/src/model/entities/entity.cpp
    ${PROJECT_SOURCE_DIR}/src/model/entities/entity.h
    ${PROJECT_SOURCE_DIR}/src/model/entities/hero/hero.h
    ${PROJECT_SOURCE_DIR}/src/model/entities/portal/portal.h
)

find_package(SDL2 REQUIRED)

add_executable(
    bfs-rogue
    ${SOURCES}
)

target_link_libraries(
    bfs-rogue
    PRIVATE SDL2::SDL2
)
