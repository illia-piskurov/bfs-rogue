/* Author: Illia Piskurov */

#ifndef BFS_H
#define BFS_H

#include <queue>
#include <vector>

#include "../entities/hero/hero.h"
#include "../entities/portal/portal.h"
#include "../game_level/game_level.h"
#include "../point/point.h"

inline std::vector<Point> BFS(GameLevel* game_level, Hero* hero, Portal* portal)
{
    const int height = config::game_level::kMaxHeight;
    const int width = config::game_level::kMaxWidth;

    bool visited[height][width] = { false };

    std::queue<Point> queue;

    auto start = hero->pos();
    auto end = portal->pos();

    queue.push(start);
    visited[start.y][start.x] = true;

    int dx[] = { 0, 0, -1, 1 };
    int dy[] = { -1, 1, 0, 0 };

    std::vector<Point> shortestPaths(height * width);

    while (!queue.empty()) {
        Point current = queue.front();
        queue.pop();

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < width && ny < height) {
                if (!visited[ny][nx] && game_level->grid(ny, nx) != tiles::TileTypes::kWall) {
                    queue.push(Point(nx, ny));
                    visited[ny][nx] = true;

                    shortestPaths[ny * width + nx] = current;
                }
            }
        }
    }

    int destX = end.x;
    int destY = end.y;

    std::vector<Point> result;

    if (visited[destY][destX]) {
        Point current(destX, destY);
        while (current.x != start.x || current.y != start.y) {
            current = shortestPaths[current.y * width + current.x];
            result.push_back(Point(current.x, current.y));
        }
    }

    return result;
}

#endif