#ifndef RIGID_BODY_COMPONENT_H
#define RIGID_BODY_COMPONENT_H

#include "IComponent.h"

struct RigidBodyComponent : public IComponent {
public:
    int width, height;
    RigidBodyComponent() = default;
    ~RigidBodyComponent() = default;
    RigidBodyComponent(const RigidBodyComponent&) = default;
    RigidBodyComponent(int w, int h) : width(w), height(h) {}
};

#endif
