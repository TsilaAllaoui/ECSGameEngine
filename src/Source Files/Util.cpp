#include <cassert>
#include "Util.h"
#include "Config.h"

std::shared_ptr<Util> Util::_instance = nullptr;

std::shared_ptr<Util> Util::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = std::shared_ptr<Util>();
    }
    return _instance;
}

b2Vec2 Util::sdlCoordinatesToBox2d(int x, int y)
{
    return b2Vec2(x, Config::getWindowHeight() - y);
}
