#ifndef UTIL_H
#define UTIL_H

#include <memory>

class Util {
    static std::shared_ptr<Util> _instance;
    Util() = default;

public:
    Util(const Util&) = delete;
    Util& operator=(const Util&) = delete;
    ~Util() = default;

    static std::shared_ptr<Util> getInstance();
};

#endif