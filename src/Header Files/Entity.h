// Entity.h
#ifndef ENTITY_H
#define ENTITY_H

#include <unordered_map>
#include <memory>
#include "IComponent.h"

using EntityID = std::size_t;

class Entity {
public:
    Entity(EntityID id_) : id(id_) {}

    template <typename T>
    void addComponent(T component) {
        components[typeid(T).name()] = std::make_shared<T>(component);
    }

    template <typename T>
    std::shared_ptr<T> getComponent() {
        return std::static_pointer_cast<T>(components[typeid(T).name()]);
    }

    EntityID getID() const { return id; }

    template <typename T>
    bool hasComponent() {
        return components.find(typeid(T).name()) != components.end();
    }

private:
    EntityID id;
    std::unordered_map<const char*, std::shared_ptr<IComponent>> components; // Map of components
};

#endif // ENTITY_H
