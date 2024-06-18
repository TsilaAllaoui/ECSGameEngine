#include "../Header Files/MovementSystem.h"

void MovementSystem::update(Entity &entity)
{
    if (entity.hasComponent<PositionComponent>() && entity.hasComponent<VelocityComponent>())
    {
        auto position = entity.getComponent<PositionComponent>();
        auto velocity = entity.getComponent<VelocityComponent>();

        position->x += velocity->dx;
        position->y += velocity->dy;
    }
}