#include "ui/Window.h"
#include "raylib.h"

using namespace RBreakout::UI;

void Window::Init() {
  auto [width, height, targetFps, windowTitle] = options;
  InitWindow(width, height, windowTitle.c_str());
  SetTargetFPS(targetFps);
}

bool Window::IsWindowOpen() const {
  return !WindowShouldClose();
}

void Window::Shutdown() {
  CloseWindow();
}
