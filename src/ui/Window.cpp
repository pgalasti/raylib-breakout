#include "ui/Window.h"
#include "raylib.h"

using namespace RBreakout::UI;

void Window::Init() {
  auto [width, height, targetFps, windowTitle] = options;

  SetConfigFlags(FLAG_VSYNC_HINT); // TODO add to options later
  InitWindow(width, height, windowTitle.c_str());
  SetWindowMinSize(320, 240);

  const RenderTexture2D target { LoadRenderTexture(width, height) };
  SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);
  
  SetTargetFPS(targetFps);
}

bool Window::IsWindowOpen() const {
  return !WindowShouldClose();
}

void Window::Shutdown() {
  CloseWindow();
}
