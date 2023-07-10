/* Author: Illia Piskurov */

#ifndef CONFIG_H
#define CONFIG_H

namespace config {
namespace game_level {
    constexpr int kMaxHeight { 21 };
    constexpr int kMaxWidth { 32 };
    constexpr int kRoomsNum { 20 };
    constexpr int kMaxRoomHeight { 3 };
    constexpr int kMinRoomHeight { 2 };
    constexpr int kMaxRoomWidth { 3 };
    constexpr int kMinRoomWidth { 2 };
    constexpr int kBridgeWidth { 1 };
} // namespace game_level
namespace window {
    constexpr char kWindowTitle[] { "BFS Rogue" };
    constexpr int kTileSize { 16 };
    constexpr int kScale { 2 };
    constexpr int kScreenWidth { game_level::kMaxWidth * kTileSize * kScale };
    constexpr int kScreenHeight { game_level::kMaxHeight * kTileSize * kScale };
} // namespace window
namespace path_of_images {
    constexpr char kIconPath[] { "../res/img/icon.bmp" };
    constexpr char kFloorTilePath[] { "../res/img/floor.bmp" };
    constexpr char kWallTilePath[] { "../res/img/wall.bmp" };
    constexpr char kHeroTilePath[] { "../res/img/hero.bmp" };
    constexpr char kPortalTilePath[] { "../res/img/portal.bmp" };
    constexpr char kPathTilePath[] { "../res/img/path.bmp" };
} // namespace path_of_images
}; // namespace config

#endif
