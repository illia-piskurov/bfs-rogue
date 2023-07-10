/* Author: Illia Piskurov */

#ifndef HERO_H
#define HERO_H

#include <tuple>

#include "../entity.h"

class Hero : public Entity {
public:
    Hero(GameLevel* game_level)
        : Entity(game_level) {};
};

#endif
