/* Author: Illia Piskurov */

#ifndef ENTITY_H
#define ENTITY_H

#include <tuple>

#include "../game_level/game_level.h"
#include "../point/point.h"

class Entity {
public:
    Entity(GameLevel* game_level);
    virtual Point pos();

protected:
    Point pos_;
};

#endif