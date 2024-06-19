#include <iostream>
#include <thread>
#include "./Header Files/EntityManager.h"
#include "./Header Files/PositionComponent.h"
#include "./Header Files/VelocityComponent.h"
#include "./Header Files/TextureComponent.h"
#include "./Header Files/RigidBodyComponent.h"
#include "./Header Files/MovementSystem.h"
#include "./Header Files/RenderSystem.h"
#include "SDL.h"

int main(int argc, char *argv[]) {
    EntityManager entityManager;

    // Create entities
    EntityID entity1 = entityManager.createEntity();
    EntityID entity2 = entityManager.createEntity();

    // Add components to entities
    entityManager.getEntity(entity1).addComponent(PositionComponent(100, 225));
    entityManager.getEntity(entity1).addComponent(VelocityComponent(1, -2));
    entityManager.getEntity(entity1).addComponent(TextureComponent(125,46,200));
    entityManager.getEntity(entity1).addComponent(RigidBodyComponent((rand() % 41) + 10, (rand() % 41) + 10));

    entityManager.getEntity(entity2).addComponent(PositionComponent(305, 150));
    entityManager.getEntity(entity2).addComponent(VelocityComponent(-5, 2));
    entityManager.getEntity(entity2).addComponent(TextureComponent(5,199,5));
    entityManager.getEntity(entity2).addComponent(RigidBodyComponent((rand() % 41) + 10, (rand() % 41) + 10));


    MovementSystem movementSystem;
    RenderSystem renderingSystem;

    SDL_Event event;
    bool quit = false;

    while(!quit) {

        Uint32 frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        movementSystem.update(entityManager.getEntities());
        renderingSystem.update(entityManager.getEntities());
        
        Uint32 frameEnd = SDL_GetTicks();
        Uint32 frameDuration = frameEnd - frameStart;
        if (frameDuration < 1000 / 60) {
            SDL_Delay(1000 / 60 - frameDuration);
        }
    }

    return 0;
}
