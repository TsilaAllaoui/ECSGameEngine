#include "Config.h"

std::shared_ptr<Config> Config::_instance = nullptr;
std::string Config::windowTitle = "ECSGameEngine";
int Config::windowWidth = 640;
int Config::windowHeight = 480;


std::shared_ptr<Config> Config::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = std::shared_ptr<Config>();
    }
    return _instance;
}

std::string Config::getWindowTitle() {
    return windowTitle; 
}

int Config::getWindowWidth() { 
    return windowWidth; 
}

int Config::getWindowHeight() {
    return windowHeight; 
}