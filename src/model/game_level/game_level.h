/* Author: Illia Piskurov */

#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <tuple>

#include "../../config.h"
#include "tile_types.h"
#include "../point/point.h"

class GameLevel {
public:
    typedef tiles::TileTypes Grid[config::game_level::kMaxHeight]
                                 [config::game_level::kMaxWidth];

    GameLevel();
    Point getRandomWallPoint();
    void DebugConsoleShow() const;
    constexpr int max_height();
    constexpr int max_width();
    tiles::TileTypes grid(int y, int x) const;

private:
    Grid grid_;

    void nullGrid();
    void buildBridge(int x1, int x2, int y1, int y2);
    bool isFirstRoom(int x, int y);
    void generateGrid();
    Point generateOneRoom(int num_of_room);
};

#endif
