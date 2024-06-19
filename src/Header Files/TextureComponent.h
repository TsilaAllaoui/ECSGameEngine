// PositionComponent.h
#ifndef TEXTURE_COMPONENT_H
#define TEXTURE_COMPONENT_H

#include <cassert>
#include "IComponent.h"
#include "Config.h"
#include "SDL.h"
#include <ctime>

class TextureComponent : public IComponent
{
public:
    SDL_Surface *surface;
    SDL_Texture* texture;
    TextureComponent() {
        surface = nullptr;
        texture = nullptr;
    }
    ~TextureComponent() {
        // SDL_FreeSurface(surface);
        // SDL_DestroyTexture(texture);
    }
    TextureComponent(const TextureComponent &) = default;
    TextureComponent(const std::string &filePath) : TextureComponent()
    {
        // std::srand(static_cast<unsigned int>(std::time(nullptr)));

        // // Generate random color components (RGB)
        // uint8_t r = rand() % 256; // Red component
        // uint8_t g = rand() % 256; // Green component
        // uint8_t b = rand() % 256; // Blue component

        // SDL_Rect rect {0, 0, 50, 50};
        // surface = SDL_CreateRGBSurface(0, rect.x, rect.y, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
        // SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, r, g, b)); 
        // assert(surface && "Surface null");

        // // Fill surface with the specified color
        // SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, r, g, b));

        // // Convert surface to texture
        // texture = SDL_CreateTextureFromSurface(renderer, surface);
        // if (!texture) {
        //     std::cerr << "SDL_CreateTextureFromSurface failed: " << SDL_GetError() << std::endl;
        // }

        // // Free the surface, as it's no longer needed
    }
};

#endif // POSITION_COMPONENT_H
