# 1. Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# 2. Project name and version
project(RaylibBreakout VERSION 1.0)

# 3. Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4. Add raylib
add_subdirectory(external/raylib)

# 5. Add the executable
add_executable(breakout
  src/main.cpp
  src/ui/Window.cpp
  src/core/Game.cpp
  src/ui/Renderer.cpp
  src/core/EntityManager.cpp
  src/core/EventBus.cpp
  src/core/EntityEventCallback.cpp
  src/core/PollInput.cpp
  src/core/Level.cpp
  src/game/TestLevel.cpp
)

target_include_directories(breakout PRIVATE include/ray-breakout)
target_link_libraries(breakout PRIVATE raylib)
target_compile_definitions(breakout PRIVATE $<$<CONFIG:Debug>:_DEBUG>)
