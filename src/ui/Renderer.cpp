#include "ui/Renderer.h"

#include "raylib.h"

using namespace RBreakout::UI;

Renderer::Renderer(Window* pWindow) : m_pWindow(pWindow) {}

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

  const WindowOptions& windowOptions {m_pWindow->GetWindowOptions()};
  
  const auto [windowWidth, windowHeight, ignore1, ignore2] = windowOptions;
  const float scale {std::min(windowWidth / m_VirtualWidth, windowHeight / m_VirtualHeight)};

  for(const Core::Entity& entity : entities) {
    
    // Hardcoded logic for now
    // Add logic to determine the entity shape and appropriate way to render
    DrawRectangle(entity.position.pos[0]*scale, entity.position.pos[1]*scale, 80*scale, 80*scale, RAYWHITE);

  }
}
