#include "core/Game.h"
#include "core/Events.h"
#include "core/Geometry.h"

#include "raylib.h"

using namespace RBreakout::Core;

Game::Game() 
  : m_pRenderer { std::make_unique<UI::Renderer>() },
    m_pEntityManager { std::make_unique<EntityManager>(EntityManager::Options{300uz}) },
    m_pFrameTimer { std::make_unique<RLFrameTimer>() },
    m_pEntityEventCallback { std::make_unique<EntityEventCallback>()}
{
  UI::WindowOptions options {800, 350, 120, "Breakout"};
  m_pWindow = std::make_unique<UI::Window>(options);

  m_pEventBus = std::make_unique<EventBus>(*m_pEntityEventCallback);
}

void Game::Start() {
  m_pWindow->Init();

  // Move to level loading later
  Point2Df position;
  position.x = 360;
  position.y = 60;
  const EntityID id {m_pEntityManager->RegisterEntity(position)};

  m_pEventBus->Subscribe(id, EventType::PlayerMovement);
  m_pEntityEventCallback->Register(id, [this, id](Event* pEvent) {
      Entity* pEntity {m_pEntityManager->Lookup(id)};
      if(!pEntity) {
        return false;
      }

      const Vector2Df moveVector = dynamic_cast<MovementEvent*>(pEvent->second.get())->vec;
      pEntity->position += moveVector;
      return true;
    }
  );
}

void Game::UpdateGameState() {
  m_pFrameTimer->Tick();
  const double lastTime { m_pFrameTimer->GetFrameTime() };

  // Test code. Will move to level logic
  Event testMoveEvent { EventType::PlayerMovement, std::make_unique<MovementEvent>(Vector2Df{1.0f, 1.0f}) };
  m_pEventBus->QueueEvent(std::move(testMoveEvent));
  m_pEventBus->InvokeEvents();
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
