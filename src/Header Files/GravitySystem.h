#ifndef GRAVITY_SYSTEM_H
#define GRAVITY_SYSTEM_H

#include "PositionComponent.h"
#include "VelocityComponent.h"
#include "ISystem.h"
#include "box2d/box2d.h"

class GravitySystem : public ISystem {
    b2Vec2 gravity;
public:
    GravitySystem();
    ~GravitySystem() = default;
    void update(std::vector<std::unique_ptr<Entity>>& entities) override;
};

#endif
