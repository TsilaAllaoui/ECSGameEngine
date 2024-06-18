#include "../Header Files/EntityManager.h"

EntityID EntityManager::createEntity()
{
    EntityID id = nextID++;
    entities.emplace_back(std::make_unique<Entity>(id));
    return id;
}

void EntityManager::destroyEntity(EntityID id)
{
    // Implement entity deletion logic
}

Entity &EntityManager::getEntity(EntityID id) const
{
    for (const auto &entity : entities)
    {
        if (entity->getID() == id)
        {
            return *entity;
        }
    }
    // Handle entity not found
    throw std::runtime_error("Entity not found");
}