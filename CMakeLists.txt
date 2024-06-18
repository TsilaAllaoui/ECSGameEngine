cmake_minimum_required(VERSION 3.16)
project(ECSGameEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add SDL as a subdirectory
# add_subdirectory(external/SDL)

#Add include directories
include_directories("${PROJECT_SOURCE_DIR}/src/Header Files")

# Add source files
set(SOURCES
    src/main.cpp
    src/Source\ Files/EntityManager.cpp
    src/Source\ Files/MovementSystem.cpp
)

add_executable(ECSGameEngine ${SOURCES})

# # Link SDL3
# target_include_directories(ECSGameEngine PRIVATE external/SDL/include)
# target_link_libraries(ECSGameEngine PRIVATE SDL3::SDL3-shared)
