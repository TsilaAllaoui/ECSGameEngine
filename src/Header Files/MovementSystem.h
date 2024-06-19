// MovementSystem.h
#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

#include "PositionComponent.h"
#include "VelocityComponent.h"
#include "ISystem.h"

class MovementSystem : public ISystem {
public:
    ~MovementSystem() = default;
    void update(std::vector<std::unique_ptr<Entity>>& entities) override;
};

#endif // MOVEMENT_SYSTEM_H
