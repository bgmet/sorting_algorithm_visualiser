cmake_minimum_required(VERSION 3.5)
project(Visualiser)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64")

# Sources
file(GLOB SOURCES "src/*.cpp")
include_directories("lib")

# Find SDL3 via CMake config
find_package(SDL3 REQUIRED CONFIG)

find_package(SDL3_ttf REQUIRED CONFIG)

# set(SDL3_TTF_INCLUDE_DIR "/usr/local/Cellar/sdl3_ttf/3.2.2/include/SDL3_ttf")
# set(SDL3_TTF_LIBRARY "/usr/local/Cellar/sdl3_ttf/3.2.2/lib/libSDL3_ttf.0.2.2.dylib")

add_executable(visualiser ${SOURCES})


target_link_libraries(visualiser
    SDL3_ttf::SDL3_ttf
    SDL3::SDL3
)