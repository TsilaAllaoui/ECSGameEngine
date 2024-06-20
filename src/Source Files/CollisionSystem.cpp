#include "CollisionSystem.h"
#include "Config.h"
#include "Util.h"

CollisionSystem::CollisionSystem()
{
    world = new b2World(b2Vec2(0.0f, -10.0f));
    ground = new b2BodyDef();
    groundBox = new b2PolygonShape();
    auto pos = Util::sdlCoordinatesToBox2d(0, Config::getWindowHeight());
    ground->position.Set(pos.x, pos.y);
    groundBody = world->CreateBody(ground);
    groundBox->SetAsBox(Config::getWindowWidth() / 2, Config::getWindowHeight() / 2);
    groundBody->CreateFixture(groundBox, 0.0f);
}

CollisionSystem::~CollisionSystem() {
    world->DestroyBody(groundBody);
}

void CollisionSystem::update(std::vector<std::unique_ptr<Entity>> &entities)
{
    world->Step(1.0f / 60.0f, 3, 2);
}
