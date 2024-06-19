#include "GravitySystem.h"
#include "box2d/box2d.h"
#include "PositionComponent.h"
#include "VelocityComponent.h"
#include "RigidBodyComponent.h"
#include <memory>

GravitySystem::GravitySystem()
{
    gravity = b2Vec2(0.0f, -10.0f);
}

void GravitySystem::update(std::vector<std::unique_ptr<Entity>> &entities)
{
    for (auto& entity : entities) {
        if (entity->hasComponent<VelocityComponent>()) {
            auto velocity = entity->getComponent<VelocityComponent>();
            velocity->dy += gravity.y;
        }
    }
}