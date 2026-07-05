#ifndef RBREAKOUT_GAME_H
#define RBREAKOUT_GAME_H

#include "ui/Window.h"
#include "ui/Renderer.h"
#include "core/EntityManager.h"
#include "core/Timer.h"

#include <memory>
#include <unordered_map>

namespace RBreakout::Core {



class Game {
public:
  Game(/*Can add options via params later*/);

  void Start();
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
};

} // RBreakout::Core


#endif // RBREAKOUT_GAME_H
