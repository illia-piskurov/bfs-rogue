/* Author: Illia Piskurov */

#include "view.h"
#include <SDL_render.h>

View::View()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    createWindow();
    setWindowIcon();
    createRenderer();
    SDL_RenderSetScale(renderer_, config::window::kScale,
        config::window::kScale);

    model_ = std::make_unique<Model>();
    tilesTextures_ = model_->LoadTilesTextures(renderer_);
}

View::~View()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);

    for (auto texture : tilesTextures_) {
        SDL_DestroyTexture(texture);
    }
}

void View::createWindow()
{
    window_ = SDL_CreateWindow(
        config::window::kWindowTitle, SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, config::window::kScreenWidth,
        config::window::kScreenHeight, SDL_WINDOW_ALLOW_HIGHDPI);

    if (NULL == window_) {
        printf("SDL_CreateWindow error: %s\n", SDL_GetError());
    }
}

void View::createRenderer()
{
    renderer_ = SDL_CreateRenderer(
        window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (NULL == renderer_) {
        printf("SDL_CreateRenderer error: %s\n", SDL_GetError());
    }
}

void View::DrawFrame()
{
    SDL_RenderClear(renderer_);
    drawGameMap();
    drawPath();
    drawHero();
    drawPortal();
    SDL_RenderPresent(renderer_);
}

void View::drawGameMap()
{
    for (int y = 0; y < config::game_level::kMaxHeight; y++) {
        for (int x = 0; x < config::game_level::kMaxWidth; x++) {
            SDL_Texture* texture = tilesTextures_.at(int(model_->game_level()->grid(y, x)));
            applySurface(x * config::window::kTileSize,
                y * config::window::kTileSize, texture);
        }
    }
}

void View::drawHero()
{
    auto pos = model_->hero()->pos();
    SDL_Texture* texture = tilesTextures_.at(int(tiles::TileTypes::kHero));
    applySurface(pos.x * config::window::kTileSize,
        pos.y * config::window::kTileSize, texture);
}

void View::drawPortal()
{
    auto pos = model_->portal()->pos();
    SDL_Texture* texture = tilesTextures_.at(int(tiles::TileTypes::kPortal));
    applySurface(pos.x * config::window::kTileSize,
        pos.y * config::window::kTileSize, texture);
}

void View::drawPath()
{
    auto path = model_->path;
    SDL_Texture* texture = tilesTextures_.at(int(tiles::TileTypes::kPath));
    for (auto i = path.begin(); i < path.end(); i++) {
        applySurface(i->x * config::window::kTileSize,
            i->y * config::window::kTileSize, texture);
    }
}

void View::applySurface(int x, int y, SDL_Texture* texture)
{
    SDL_Rect position;
    position.x = x;
    position.y = y;

    SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
    SDL_RenderCopy(renderer_, texture, NULL, &position);
}

void View::setWindowIcon()
{
    SDL_SetWindowIcon(window_, SDL_LoadBMP(config::path_of_images::kIconPath));
}

void View::regenModel()
{
    model_ = std::make_unique<Model>();
}