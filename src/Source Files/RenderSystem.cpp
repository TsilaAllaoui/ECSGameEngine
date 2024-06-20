#include "PositionComponent.h"
#include "TextureComponent.h"
#include "RigidBodyComponent.h"
#include "RenderSystem.h"
#include "Config.h"
#include <memory>
#include "SDL.h"

RenderSystem::RenderSystem()
{
    assert(SDL_Init(SDL_INIT_VIDEO) == 0 && "Can't initialize SDL!");
    assert(
        SDL_CreateWindowAndRenderer(
            Config::getWindowWidth(),
            Config::getWindowHeight(),
            SDL_WINDOW_SHOWN,
            &window,
            &renderer) == 0 &&
        "Can't create window and renderer!");
}

RenderSystem::~RenderSystem()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void RenderSystem::update(std::vector<std::unique_ptr<Entity>> &entities)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (auto &entity : entities)
    {
        if (entity->hasComponent<TextureComponent>() && entity->hasComponent<RigidBodyComponent>())
        {
            auto rigidBody = entity->getComponent<RigidBodyComponent>();
            auto textureComponent = entity->getComponent<TextureComponent>();
            auto texture = entity->getComponent<TextureComponent>()->texture;
            texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, rigidBody->w, rigidBody->h);
            assert(texture && "Texture null");

            // Lock the texture for writing pixel data
            void *pixels = nullptr;
            int pitch = 0;
            SDL_LockTexture(texture, nullptr, &pixels, &pitch);

            // Fill the texture with a solid color (red in this example)
            Uint32 redColor = SDL_MapRGBA(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), textureComponent->r, textureComponent->g, textureComponent->b, 255);
            Uint32 *pixelPtr = static_cast<Uint32 *>(pixels);
            int pixelCount = (rigidBody->w * rigidBody->h); // Assuming a 200x200 texture
            for (int i = 0; i < pixelCount; ++i)
            {
                pixelPtr[i] = redColor;
            }

            // Unlock texture
            SDL_UnlockTexture(texture);

            // Render the texture to the center of the screen
            SDL_Rect dstRect = {rigidBody->x, rigidBody->y, rigidBody->w, rigidBody->h};
            SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
        }
    }

    SDL_RenderPresent(renderer);
}