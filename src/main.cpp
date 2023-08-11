/* Author: Illia Piskurov */

#include "view/view.h"

#include <SDL_events.h>
#include <iostream>
#include <memory>

int main(int argv, char** args)
{
    try {
        View view;

        SDL_Event windowEvent;
        while (true) {
            if (SDL_PollEvent(&windowEvent)) {
                if (SDL_QUIT == windowEvent.type) {
                    break;
                }
                if (SDL_KEYDOWN == windowEvent.type) {
                    view.regenModel();
                }
            }

            view.DrawFrame();
        }
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
