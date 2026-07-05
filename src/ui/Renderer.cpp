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

void Renderer::Render(const EntityList& entities) {
  for(const Core::Entity& entity : entities) {
    
    // Hardcoded logic for now
    // Add logic to determine the entity shape and appropriate way to render
    DrawRectangle(entity.position.pos[0], entity.position.pos[1], 80, 80, RAYWHITE);

  }
}
