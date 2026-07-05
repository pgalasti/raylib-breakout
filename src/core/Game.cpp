#include "core/Game.h"

#include "raylib.h"

using namespace RBreakout::Core;

Game::Game() {
  UI::WindowOptions options {800, 350, 120, "Breakout"};
  m_pWindow = std::make_unique<UI::Window>(options);
  m_pRenderer = std::make_unique<UI::Renderer>();
}

void Game::Start() {
  m_pWindow->Init();


}

void Game::UpdateGameState() {

}

void Game::RenderState() {

  m_pRenderer->StartFrame();
  m_pRenderer->ClearScreen();
  m_pRenderer->EndFrame();

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
