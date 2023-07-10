/* Author: Illia Piskurov */

#include "game_level.h"

GameLevel::GameLevel()
{
    std::srand(std::time(NULL));
    generateGrid();
}

void GameLevel::generateGrid()
{
    nullGrid();

    int current_bridge_x = -1, current_bridge_y = -1, previous_bridge_x,
        previous_bridge_y;

    for (int rooms = 0; rooms < config::game_level::kRoomsNum; rooms++) {
        auto point = generateOneRoom(rooms);

        previous_bridge_y = current_bridge_y;
        previous_bridge_x = current_bridge_x;

        current_bridge_y = point.y;
        current_bridge_x = point.x;

        if (!isFirstRoom(previous_bridge_x, previous_bridge_y)) {
            buildBridge(current_bridge_x, previous_bridge_x, current_bridge_y,
                previous_bridge_y);
        }
    }
}

Point GameLevel::generateOneRoom(int num_of_room)
{
    int top_y, bottom_y, left_x, right_x;

    top_y = 1 + (std::rand() % (config::game_level::kMaxHeight - config::game_level::kMaxRoomHeight - 1));

    left_x = 1 + (std::rand() % (config::game_level::kMaxWidth - config::game_level::kMaxRoomWidth - 1));

    bottom_y = top_y + (config::game_level::kMinRoomHeight + (std::rand() % (config::game_level::kMaxRoomHeight - config::game_level::kMinRoomHeight)));

    right_x = left_x + (config::game_level::kMinRoomWidth + (std::rand() % (config::game_level::kMaxRoomWidth - config::game_level::kMinRoomWidth)));

    int y { 0 }, x { 0 };
    y = top_y + (std::rand() % (bottom_y - top_y));
    x = left_x + (std::rand() % (right_x - left_x));

    for (int y = top_y; y <= bottom_y; y++) {
        for (int x = left_x; x <= right_x; x++) {
            grid_[y][x] = tiles::TileTypes::kFloor;
        }
    }

    return Point(x, y);
}

void GameLevel::nullGrid()
{
    for (int y = 0; y < config::game_level::kMaxHeight; y++) {
        for (int x = 0; x < config::game_level::kMaxWidth; x++) {
            grid_[y][x] = tiles::TileTypes::kWall;
        }
    }
}

void GameLevel::buildBridge(int x1, int x2, int y1, int y2)
{
    int start_x, start_y, end_x, end_y;

    if (x1 < x2) {
        start_x = x1;
        start_y = y1;
        end_x = x2;
        end_y = y2;
    } else {
        start_x = x2;
        start_y = y2;
        end_x = x1;
        end_y = y1;
    }

    for (int y = start_y; y < start_y + config::game_level::kBridgeWidth; y++) {
        for (int x = start_x; x <= end_x; x++) {
            grid_[y][x] = tiles::TileTypes::kFloor;
        }
    }

    if (start_y < end_y) {
        for (int x = end_x; x < end_x + config::game_level::kBridgeWidth; x++) {
            for (int y = start_y; y <= end_y; y++) {
                grid_[y][x] = tiles::TileTypes::kFloor;
            }
        }
    } else {
        for (int x = end_x; x < end_x + config::game_level::kBridgeWidth; x++) {
            for (int y = start_y; y >= end_y; y--) {
                grid_[y][x] = tiles::TileTypes::kFloor;
            }
        }
    }
}

bool GameLevel::isFirstRoom(int x, int y)
{
    bool result;

    if (x == -1 && y == -1) {
        result = true;
    } else {
        result = false;
    }

    return result;
}

void GameLevel::DebugConsoleShow() const
{
    for (int y = 0; y < config::game_level::kMaxHeight; y++) {
        for (int x = 0; x < config::game_level::kMaxWidth; x++) {
            std::cout << char(grid_[y][x]);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

constexpr int GameLevel::max_height() { return config::game_level::kMaxHeight; }

constexpr int GameLevel::max_width() { return config::game_level::kMaxWidth; }

tiles::TileTypes GameLevel::grid(int y, int x) const { return grid_[y][x]; }

Point GameLevel::getRandomWallPoint()
{
    int x { 0 }, y { 0 };

    do {
        x = 1 + std::rand() % (config::game_level::kMaxWidth - 1);
        y = 1 + std::rand() % (config::game_level::kMaxHeight - 1);
    } while (grid_[y][x] != tiles::TileTypes::kFloor);

    return Point(x, y);
}
