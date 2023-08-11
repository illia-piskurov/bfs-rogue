/* Author: Illia Piskurov */

#include "model.h"

Model::Model()
{
    game_map_ = new GameLevel();

    hero_ = new Hero(game_map_);
    portal_ = new Portal(game_map_);

    path = BFS(game_map_, hero_, portal_);
}

Model::~Model()
{
    delete game_map_;
    delete portal_;
    delete hero_;
}

SDL_Texture* Model::LoadTexture(const char path[], SDL_Renderer* renderer)
{
    SDL_Surface* loaded_image = NULL;
    SDL_Texture* texture = NULL;

    loaded_image = SDL_LoadBMP(path);

    if (loaded_image != NULL) {
        SDL_SetColorKey(
            // BACKGROUND COLOR CONST (TODO)
            loaded_image, true,
            SDL_MapRGB(loaded_image->format, 255, 255, 255));

        texture = SDL_CreateTextureFromSurface(renderer, loaded_image);
        if (NULL == texture) {
            printf("SDL_CreateTextureFromSurface error: %s\n", SDL_GetError());
        }
        SDL_FreeSurface(loaded_image);
    } else {
        throw std::runtime_error(std::string("SDL_LoadBMP error: ") + SDL_GetError() + "\n");
    }

    return texture;
}

std::vector<SDL_Texture*> Model::LoadTilesTextures(SDL_Renderer* renderer)
{
    std::vector<SDL_Texture*> textures;

    textures.push_back(LoadTexture(config::path_of_images::kFloorTilePath, renderer));
    textures.push_back(LoadTexture(config::path_of_images::kWallTilePath, renderer));
    textures.push_back(LoadTexture(config::path_of_images::kHeroTilePath, renderer));
    textures.push_back(LoadTexture(config::path_of_images::kPortalTilePath, renderer));
    textures.push_back(LoadTexture(config::path_of_images::kPathTilePath, renderer));

    return textures;
}

const GameLevel* Model::game_level()
{
    return game_map_;
}

Hero* Model::hero()
{
    return hero_;
}

Portal* Model::portal()
{
    return portal_;
}