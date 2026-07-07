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

const InputState& Game::PollInputState() {
  m_PollInput.Poll();
  return m_PollInput.GetPollState(); 
}

void Game::UpdateGameState() {
  const InputState& inputState = PollInputState();
  
  m_pFrameTimer->Tick();
  const double lastTime { m_pFrameTimer->GetFrameTime() };


  bool moveLeft  {PollInput::IsKeyPressed(inputState, ARROW_LEFT_CODE) ||  PollInput::IsKeyPressed(inputState, std::string_view("A"))};
  bool moveRight {PollInput::IsKeyPressed(inputState, ARROW_RIGHT_CODE)};
  // Test code. Will move to level logic
  if(moveLeft) {
    Event testMoveEvent { EventType::PlayerMovement, std::make_unique<MovementEvent>(Vector2Df{-10.0f, 0.0f}) };
    m_pEventBus->QueueEvent(std::move(testMoveEvent));
  } else if(moveRight) {
    Event testMoveEvent { EventType::PlayerMovement, std::make_unique<MovementEvent>(Vector2Df{10.0f, 0.0f}) };
    m_pEventBus->QueueEvent(std::move(testMoveEvent));
  }
  
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
