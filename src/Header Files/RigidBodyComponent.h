#ifndef RIGID_BODY_COMPONENT_H
#define RIGID_BODY_COMPONENT_H

#include "box2d/box2d.h"
#include "IComponent.h"
#include "Util.h"

struct RigidBodyComponent : public IComponent {
public:
    // b2BodyDef* bodyDef;
    // b2Body *body;
    // b2PolygonShape* bodyShape;
    // b2FixtureDef* fixtureDef;

    int w, h;
    int x, y;
    RigidBodyComponent() = default;
    ~RigidBodyComponent() {
    }
    RigidBodyComponent(const RigidBodyComponent&) = default;
    RigidBodyComponent(int x_, int y_, int w_, int h_) : x(x_), y(y_), w(w_), h(h_) {
        // bodyDef = new b2BodyDef();
        // fixtureDef = new b2FixtureDef();
        // bodyShape = new b2PolygonShape();

        // auto box2dPos = Util::sdlCoordinatesToBox2d(x, y);
        // bodyDef->type = b2_dynamicBody;
        // bodyDef->position.Set(box2dPos.x, box2dPos.y);

        // bodyShape->SetAsBox(w / 2, h / 2);

        // fixtureDef->shape = bodyShape;
        // fixtureDef->density = 1.0f;
        // fixtureDef->friction = 0.3f;
    }
};

#endif
