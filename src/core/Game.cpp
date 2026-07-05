#include "core/Game.h"

#include "raylib.h"

using namespace RBreakout::Core;

Game::Game() 
  : m_pRenderer { std::make_unique<UI::Renderer>() },
    m_pEntityManager { std::make_unique<EntityManager>(EntityManager::Options{300uz}) },
    m_pFrameTimer { std::make_unique<RLFrameTimer>() }
{
  UI::WindowOptions options {800, 350, 120, "Breakout"};
  m_pWindow = std::make_unique<UI::Window>(options);
}

void Game::Start() {
  m_pWindow->Init();

  Point2Df position;
  position.x = 360;
  position.y = 60;
//  position.pos[0] = 360;
//  position.pos[1] = 60;
  m_pEntityManager->RegisterEntity(position);
}

void Game::UpdateGameState() {
  m_pFrameTimer->Tick();
  const double lastTime { m_pFrameTimer->GetFrameTime() };
}

void Game::RenderState() {

  m_pRenderer->StartFrame();
  m_pRenderer->ClearScreen();

  const auto& renderableEntities {m_pEntityManager->GetRenderableEntities()};
  m_pRenderer->Render(renderableEntities);

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
