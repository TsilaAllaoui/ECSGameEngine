// PositionComponent.h
#ifndef TEXTURE_COMPONENT_H
#define TEXTURE_COMPONENT_H

#include <cassert>
#include <memory>
#include <ctime>
#include "IComponent.h"
#include "Config.h"
#include "SDL.h"

class TextureComponent : public IComponent
{
public:
    SDL_Texture* texture;
    uint8_t r, g, b;
    TextureComponent() : r(0), g(g), b(b) {}
    ~TextureComponent() {
        // SDL_DestroyTexture(texture);
    }
    TextureComponent(const TextureComponent &) = default;
    TextureComponent(const uint8_t& r_, const uint8_t& g_, const uint8_t& b_) : r(r_), g(g_), b(b_) {}
};

#endif // POSITION_COMPONENT_H
