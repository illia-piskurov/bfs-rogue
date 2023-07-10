/* Author: Illia Piskurov */

#include "entity.h"

Entity::Entity(GameLevel* game_level)
{
    pos_ = game_level->getRandomWallPoint();
}

Point Entity::pos()
{
    return pos_;
}