#ifndef ISYSTEM_H
#define ISYSTEM_H

#include "Entity.h"

class ISystem {
public:
    virtual ~ISystem() = default;
    virtual void update(Entity&) = 0;
};

#endif