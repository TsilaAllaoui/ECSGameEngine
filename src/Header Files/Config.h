#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <memory>

class Config {
    static std::shared_ptr<Config> _instance;
    Config() = default;
    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;
    static std::string windowTitle;
    static int windowWidth;
    static int windowHeight;

public:
    ~Config() = default;
    static std::shared_ptr<Config> getInstance();
    static std::string getWindowTitle();
    static int getWindowWidth();
    static int getWindowHeight();
};

#endif