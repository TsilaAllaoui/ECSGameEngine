#include "GravitySystem.h"
#include "box2d/box2d.h"
#include "PositionComponent.h"
#include "VelocityComponent.h"
#include "RigidBodyComponent.h"
#include <memory>

GravitySystem::GravitySystem()
{
    gravity = std::make_unique<b2Vec2>(0.0f, -1.0f);
    world = std::make_unique<b2World>(*gravity);
}

void GravitySystem::update(std::vector<std::unique_ptr<Entity>> &entities)
{
    for (auto& entity : entities) {
        if (entity->hasComponent<RigidBodyComponent>()) {
            auto rigidBody = entity->getComponent<RigidBodyComponent>();
            // if (!rigidBody->body) {
            //     rigidBody->body = world->CreateBody(rigidBody->bodyDef);
            //     rigidBody->body->CreateFixture(rigidBody->fixtureDef);
            // }
        }
    }
}