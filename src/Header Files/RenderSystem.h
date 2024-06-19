#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include "SDL.h"
#include "ISystem.h"

class RenderSystem : public ISystem {
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    RenderSystem();
    ~RenderSystem();
    void update(std::vector<std::unique_ptr<Entity>> &) override;
};

#endif
