/* Author: Illia Piskurov */

#ifndef TILE_TYPES_H
#define TILE_TYPES_H

namespace tiles {
enum class TileTypes {
    kFloor = 0,
    kWall,
    kHero,
    kPortal,
    kPath
};
constexpr int kNumOfTypes { 5 };
};

#endif
