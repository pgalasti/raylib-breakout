#ifndef RBREAKOUT_GAME_H
#define RBREAKOUT_GAME_H

#include "ui/Window.h"
#include "ui/Renderer.h"
#include "core/EntityManager.h"
#include "core/Timer.h"
#include "core/EventBus.h"
#include "core/EntityEventCallback.h"
#include "core/PollInput.h"

#include <memory>
#include <unordered_map>

namespace RBreakout::Core {



class Game {
public:
  Game(/*Can add options via params later*/);

  void Start();
  const InputState& PollInputState();
  void UpdateGameState();
  void RenderState();
  void Shutdown();

  bool IsPaused() const;
  bool IsShuttingDown() const;


private:
  std::unique_ptr<UI::Window> m_pWindow;
  std::unique_ptr<UI::Renderer> m_pRenderer;
  std::unique_ptr<EntityManager> m_pEntityManager;
  std::unique_ptr<FrameTimer> m_pFrameTimer;
  std::unique_ptr<EntityEventCallback> m_pEntityEventCallback;
  std::unique_ptr<EventBus> m_pEventBus;

  PollInput m_PollInput;
};

} // RBreakout::Core


#endif // RBREAKOUT_GAME_H
