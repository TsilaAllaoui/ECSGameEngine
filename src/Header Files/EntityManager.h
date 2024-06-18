// EntityManager.h
#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <vector>
#include <memory>
#include "Entity.h"
#include <stdexcept>

class EntityManager {
public:
    EntityID createEntity();

    void destroyEntity(EntityID id);

    Entity& getEntity(EntityID id) const;

private:
    EntityID nextID = 0;
    std::vector<std::unique_ptr<Entity>> entities;
};

#endif // ENTITY_MANAGER_H
