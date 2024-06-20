#include <iostream>
#include "../Header Files/MovementSystem.h"
#include "../Header Files/RigidBodyComponent.h"
#include "../Header Files/Config.h"

void MovementSystem::update(std::vector<std::unique_ptr<Entity>>& entities)
{
    for (auto &entity : entities)
    {
        if (entity->hasComponent<PositionComponent>() && entity->hasComponent<VelocityComponent>())
        {
            auto position = entity->getComponent<PositionComponent>();
            auto velocity = entity->getComponent<VelocityComponent>();
            auto rigidBody = entity->getComponent<RigidBodyComponent>();

            /*if (position->x + rigidBody->width + velocity->dx >= Config::getWindowWidth() || position->x + velocity->dx <= 0) {
                velocity->dx *= -1;
            } else if (position->y + rigidBody->height + velocity->dy >= Config::getWindowHeight() || position->y + velocity->dy <= 0) {
                velocity->dy *= -1;
            }*/

            if (position->y + rigidBody->h >= Config::getWindowHeight()) {
                velocity->dy = 0;
            }

            position->x += velocity->dx;
            position->y += velocity->dy;
        }
    }
}