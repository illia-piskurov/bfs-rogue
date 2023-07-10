/* Author: Illia Piskurov */

#ifndef MODEL_H
#define MODEL_H

#include <SDL2/SDL.h>
#include <stdexcept>
#include <string>
#include <vector>

#include "entities/hero/hero.h"
#include "entities/portal/portal.h"
#include "game_level/game_level.h"

#include "bfs/bfs.h"

class Model {
public:
    Model();
    ~Model();
    std::vector<SDL_Texture*> LoadTilesTextures(SDL_Renderer* renderer);
    SDL_Texture* LoadTexture(const char path[], SDL_Renderer* renderer);

    const GameLevel* game_level();
    Hero* hero();
    Portal* portal();

    std::vector<Point> path;

private:
    GameLevel* game_map_;
    Hero* hero_;
    Portal* portal_;
};

#endif
