#include "ui/Renderer.h"

#include "raylib.h"

using namespace RBreakout::UI;

void Renderer::ClearScreen(RColor color/*=Black*/) {
  // Logic to map Color to Raylib colors
  ClearBackground(BLACK);
}

void Renderer::StartFrame() {
  BeginDrawing();
}

void Renderer::EndFrame() {
  EndDrawing();

}
