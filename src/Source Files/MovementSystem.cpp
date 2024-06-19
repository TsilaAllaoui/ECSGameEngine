#include <iostream>
#include "../Header Files/MovementSystem.h"

void MovementSystem::update(std::vector<std::unique_ptr<Entity>>& entities)
{
    for (auto &entity : entities)
    {
        if (entity->hasComponent<PositionComponent>() && entity->hasComponent<VelocityComponent>())
        {
            auto position = entity->getComponent<PositionComponent>();
            auto velocity = entity->getComponent<VelocityComponent>();

            position->x += velocity->dx;
            position->y += velocity->dy;

            // Print updated positions
            std::cout << "\n***********\n";
            std::cout << "Entity Position: (" << entity->getComponent<PositionComponent>()->x
                      << ", " << entity->getComponent<PositionComponent>()->y << ")" << std::endl;
            std::cout << "Entity Position: (" << entity->getComponent<PositionComponent>()->x
                      << ", " << entity->getComponent<PositionComponent>()->y << ")" << std::endl;
            std::cout << "\n***********\n";
        }
    }
}