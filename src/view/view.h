/* Author: Illia Piskurov */

#ifndef VIEW_H
#define VIEW_H

#include <SDL2/SDL.h>
#include <memory>

#include "../model/model.h"

class View {
public:
    View();
    ~View();

    void DrawFrame();
    void regenModel();

private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    std::unique_ptr<Model> model_;
    std::vector<SDL_Texture*> tilesTextures_;

    void drawGameMap();
    void drawHero();
    void drawPortal();
    void drawPath();
    void createRenderer();
    void createWindow();
    void setWindowIcon();
    void applySurface(int x, int y, SDL_Texture* texture);
};

#endif
