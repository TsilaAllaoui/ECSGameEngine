// VelocityComponent.h
#ifndef VELOCITY_COMPONENT_H
#define VELOCITY_COMPONENT_H

#include "IComponent.h"

struct VelocityComponent : public IComponent {
public:
    int dx, dy;
    VelocityComponent() = default;
    ~VelocityComponent() = default;
    VelocityComponent(const VelocityComponent&) = default;
    VelocityComponent(int dx_, int dy_) : dx(dx_), dy(dy_) {}
};

#endif // VELOCITY_COMPONENT_H
