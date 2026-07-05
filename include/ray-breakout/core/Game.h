#ifndef RBREAKOUT_GAME_H
#define RBREAKOUT_GAME_H

#include "ui/Window.h"

#include <memory>

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
};

} // RBreakout::Core


#endif // RBREAKOUT_GAME_H
