#ifndef UTIL_H
#define UTIL_H

#include <memory>
#include "box2d/box2d.h"

class Util {
    static std::shared_ptr<Util> _instance;
    Util() = default;

public:
    Util(const Util&) = delete;
    Util& operator=(const Util&) = delete;
    ~Util() = default;

    static std::shared_ptr<Util> getInstance();
    static b2Vec2 sdlCoordinatesToBox2d(int x, int y);
};

#endif