// PositionComponent.h
#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

#include "IComponent.h"

class PositionComponent : public IComponent {
public:
    int x, y;
    PositionComponent() = default;
    ~PositionComponent() = default;
    PositionComponent(const PositionComponent&) = default;
    PositionComponent(int x_, int y_) : x(x_), y(y_) {}
};

#endif // POSITION_COMPONENT_H
