#include "PositionComponent.h"
#include "TextureComponent.h"
#include "RenderSystem.h"
#include "Config.h"

RenderSystem::RenderSystem()
{
    // assert(SDL_Init(SDL_INIT_VIDEO) == 0 && "Can't initialize SDL!");
    // assert(
    //     SDL_CreateWindowAndRenderer(
    //         Config::getWindowWidth(),
    //         Config::getWindowHeight(),
    //         SDL_WINDOW_SHOWN,
    //         &window,
    //         &renderer) == 0 &&
    //     "Can't create window and renderer!");
}

RenderSystem::~RenderSystem()
{
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    SDL_Quit();
}

void RenderSystem::update(std::vector<std::unique_ptr<Entity>> &entities)
{
    /*SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (auto &entity : entities)
    {
        if (entity->hasComponent<PositionComponent>() && entity->hasComponent<TextureComponent>())
        {
            auto position = entity->getComponent<PositionComponent>();
            // auto texture = entity->getComponent<TextureComponent>();
            // if (!texture->texture) {
            //     SDL_CreateTextureFromSurface(renderer, texture->surface);
            // }
            // SDL_Rect posRect {position->x, position->y};
            // SDL_RenderCopy(renderer, texture->texture, NULL, NULL);

            // Generate random color values
            Uint8 r = rand() % 256;
            Uint8 g = rand() % 256;
            Uint8 b = rand() % 256;

            // Set the color for drawing
            SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);

            // Create a rectangle with random dimensions and position
            int rectWidth = rand() % 200 + 50;       // Random width between 50 and 250
            int rectHeight = rand() % 200 + 50;      // Random height between 50 and 250
            int rectX = rand() % (800 - rectWidth);  // Random x position within window width
            int rectY = rand() % (600 - rectHeight); // Random y position within window height
            SDL_Rect rect = {rectX, rectY, rectWidth, rectHeight};

            // Render the filled rectangle
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    SDL_RenderPresent(renderer);*/
}