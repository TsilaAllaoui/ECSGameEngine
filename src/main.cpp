#include <iostream>
#include "./Header Files/EntityManager.h"
#include "./Header Files/Entity.h"
#include "./Header Files/IComponent.h"
#include "./Header Files/PositionComponent.h"
#include "./Header Files/VelocityComponent.h"

int main() {
    EntityManager entityManager;

    // Create entities
    EntityID entity1 = entityManager.createEntity();
    EntityID entity2 = entityManager.createEntity();

    // Add components to entities
    entityManager.getEntity(entity1).addComponent(PositionComponent(10.0f, 20.0f));
    entityManager.getEntity(entity1).addComponent(VelocityComponent(1.0f, -0.5f));

    entityManager.getEntity(entity2).addComponent(PositionComponent(5.0f, 15.0f));
    entityManager.getEntity(entity2).addComponent(VelocityComponent(-0.5f, 2.0f));

    // Check for components and update entities
    if (entityManager.getEntity(entity1).hasComponent<PositionComponent>() 
        && entityManager.getEntity(entity1).hasComponent<VelocityComponent>()) {
        auto position = entityManager.getEntity(entity1).getComponent<PositionComponent>();
        auto velocity = entityManager.getEntity(entity1).getComponent<VelocityComponent>();

        position->x += velocity->dx;
        position->y += velocity->dy;
    }

    if (entityManager.getEntity(entity2).hasComponent<PositionComponent>() 
        && entityManager.getEntity(entity2).hasComponent<VelocityComponent>()) {
        auto position = entityManager.getEntity(entity2).getComponent<PositionComponent>();
        auto velocity = entityManager.getEntity(entity2).getComponent<VelocityComponent>();

        position->x += velocity->dx;
        position->y += velocity->dy;
    }

    // Print updated positions
    std::cout << "Entity 1 Position: (" << entityManager.getEntity(entity1).getComponent<PositionComponent>()->x
              << ", " << entityManager.getEntity(entity1).getComponent<PositionComponent>()->y << ")" << std::endl;
    std::cout << "Entity 2 Position: (" << entityManager.getEntity(entity2).getComponent<PositionComponent>()->x
              << ", " << entityManager.getEntity(entity2).getComponent<PositionComponent>()->y << ")" << std::endl;

    return 0;
}
