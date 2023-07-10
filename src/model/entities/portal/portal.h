/* Author: Illia Piskurov */

#ifndef PORTAL_H
#define PORTAL_H

#include "../entity.h"

class Portal : public Entity {
public:
    Portal(GameLevel* game_level)
        : Entity(game_level) {};
};

#endif