#include <iostream>
#include <thread>
#include "./Header Files/EntityManager.h"
#include "./Header Files/PositionComponent.h"
#include "./Header Files/VelocityComponent.h"
// #include "./Header Files/TextureComponent.h"
#include "./Header Files/MovementSystem.h"
// #include "./Header Files/RenderSystem.h"

int main(int argc, char **argv) {
    EntityManager entityManager;

    // Create entities
    EntityID entity1 = entityManager.createEntity();
    EntityID entity2 = entityManager.createEntity();

    // Add components to entities
    entityManager.getEntity(entity1).addComponent(PositionComponent(10.0f, 20.0f));
    entityManager.getEntity(entity1).addComponent(VelocityComponent(1.0f, -0.5f));
    // entityManager.getEntity(entity1).addComponent(TextureComponent("../Image Files/idle.png"));

    entityManager.getEntity(entity2).addComponent(PositionComponent(5.0f, 15.0f));
    entityManager.getEntity(entity2).addComponent(VelocityComponent(-0.5f, 2.0f));
    // entityManager.getEntity(entity2).addComponent(TextureComponent("../Image Files/idle.png"));


    MovementSystem movementSystem;
    // RenderSystem renderingSystem;

    while(true) {
        movementSystem.update(entityManager.getEntities());
        // renderingSystem.update(entityManager.getEntities());
        std::this_thread::sleep_for(std::chrono::seconds(15));
    }



    return 0;
}
