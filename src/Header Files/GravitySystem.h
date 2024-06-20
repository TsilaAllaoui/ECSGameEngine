#ifndef GRAVITY_SYSTEM_H
#define GRAVITY_SYSTEM_H

#include "PositionComponent.h"
#include "VelocityComponent.h"
#include "ISystem.h"
#include "box2d/box2d.h"

class GravitySystem : public ISystem {
    std::unique_ptr<b2Vec2> gravity;
    std::unique_ptr<b2World> world;
public:
    GravitySystem();
    ~GravitySystem() = default;
    void update(std::vector<std::unique_ptr<Entity>>& entities) override;
};

#endif
