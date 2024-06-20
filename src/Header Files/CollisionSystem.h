#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include "PositionComponent.h"
#include "VelocityComponent.h"
#include "box2d/box2d.h"
#include "ISystem.h"

class CollisionSystem : public ISystem {
public:
    b2World* world;
    b2BodyDef* ground;
    b2PolygonShape* groundBox;
    b2Body* groundBody;
    
    CollisionSystem();
    ~CollisionSystem();
    void update(std::vector<std::unique_ptr<Entity>>& entities) override;
};

#endif
