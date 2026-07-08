#include "core/Game.h"
#include "core/Events.h"
#include "core/Geometry.h"
#include "game/TestLevel.h"

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

  const EntityID generalEntity {m_pEntityManager->RegisterEntity()};
  m_pEventBus->Subscribe(generalEntity, EventType::CreatePlayer);
  m_pEntityEventCallback->Register(generalEntity, [this, generalEntity](Event* pEvent) {
    const EventType eventType = pEvent->first;
    EventDetails* pEventDetails = pEvent->second.get();

    // Maybe move this to a defined function elsewhere
    if(eventType == EventType::CreatePlayer) {
      auto createPlayerEvent {dynamic_cast<CreatePlayerEvent*>(pEventDetails)};
      const EntityID playerId {m_pEntityManager->RegisterEntity(createPlayerEvent->startPosition, EntityOptions{.doRender = true})};
      m_pEventBus->Subscribe(playerId, EventType::PlayerMovement);
      m_pEntityEventCallback->Register(playerId, [this, playerId](Event* pEvent) {
        Entity* pEntity {m_pEntityManager->Lookup(playerId)};
        if(!pEntity) {
          return false;
        }

        const Vector2Df moveVector = dynamic_cast<MovementEvent*>(pEvent->second.get())->vec;
        pEntity->position += moveVector;
        return true;
      });
    }

    return true;
  });
  

  // Load Level
  // TODO integrate with game class
  RBreakout::Game::TestLevel testLevel(*m_pEventBus);
  testLevel.Initialize();
  // Do a one time InvokeEvents from level loading
  m_pEventBus->InvokeEvents();
}

const InputState& Game::PollInputState() {
  m_PollInput.Poll();
  return m_PollInput.GetPollState(); 
}

void Game::UpdateGameState() {
  const InputState& inputState = PollInputState();
  
  m_pFrameTimer->Tick();
  const double lastTime { m_pFrameTimer->GetFrameTime() };


  bool moveLeft  {PollInput::IsKeyPressed(inputState, {ARROW_LEFT_CODE, "A"})};
  bool moveRight {PollInput::IsKeyPressed(inputState, {ARROW_RIGHT_CODE, "D"})};

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
