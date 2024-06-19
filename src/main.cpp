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
    long nbEntities = 100;
    EntityManager entityManager;

    if (argc == 2) {
        nbEntities = std::atoi(argv[1]);
    }
    for (auto i=0; i<nbEntities; i++) {
        EntityID entity = entityManager.createEntity();
        entityManager.getEntity(entity).addComponent(PositionComponent(rand() % Config::getWindowWidth(), rand() % Config::getWindowHeight()));
        entityManager.getEntity(entity).addComponent(VelocityComponent(rand() % -2 + rand() % 5, rand() % -2 + rand() % 5));
        entityManager.getEntity(entity).addComponent(TextureComponent(rand() % 255,rand() % 255, rand() % 255));
        entityManager.getEntity(entity).addComponent(RigidBodyComponent((rand() % 41) + 10, (rand() % 41) + 10));
    }

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
