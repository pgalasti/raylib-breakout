#include "core/Game.h"

#include "raylib.h"

using namespace RBreakout::Core;

Game::Game() {
  UI::WindowOptions options {800, 350, 120, "Breakout"};
  m_pWindow = std::make_unique<UI::Window>(options);
}

void Game::Start() {
  m_pWindow->Init();


}

void Game::UpdateGameState() {

}

void Game::RenderState() {
  //Replace with class renderer logic
  BeginDrawing();
  ClearBackground(RAYWHITE);
  EndDrawing();
}

void Game::Shutdown() {
  m_pWindow->Shutdown();
}

bool Game::IsPaused() const {
  return false;
}

bool Game::IsShuttingDown() const {
  return !m_pWindow->IsWindowOpen();
}
