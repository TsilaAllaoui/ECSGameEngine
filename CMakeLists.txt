cmake_minimum_required(VERSION 3.16)
project(ECSGameEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add SDL as a subdirectory
add_subdirectory(external/SDL)
add_subdirectory(external/box2d)

#Add include directories
include_directories("${PROJECT_SOURCE_DIR}/src/Header Files")
include_directories(${PROJECT_SOURCE_DIR}/external/SDL/include)
include_directories(${PROJECT_SOURCE_DIR}/external/box2d/include)

# Add source files
set(SOURCES
    src/main.cpp
    src/Source\ Files/EntityManager.cpp
    src/Source\ Files/MovementSystem.cpp
    src/Source\ Files/Util.cpp
    src/Source\ Files/Config.cpp
    src/Source\ Files/RenderSystem.cpp
    src/Source\ Files/GravitySystem.cpp
)

add_executable(ECSGameEngine ${SOURCES})

# Link SDL2 libraries
target_link_libraries(ECSGameEngine SDL2::SDL2main)
target_link_libraries(ECSGameEngine SDL2::SDL2)
target_link_libraries(ECSGameEngine box2d)
