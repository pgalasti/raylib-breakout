#ifndef RBREAKOUT_ENTITY_H
#define RBREAKOUT_ENTITY_H

#include "ui/Colors.h"

namespace RBreakout::UI {

class Renderer {
public:
  Renderer() = default;
  ~Renderer() = default;
  Renderer(const Renderer&) = delete;
  Renderer(Renderer&&) = delete;
  Renderer& operator=(const Renderer&) = delete;
  Renderer& operator=(Renderer&&) = delete;

  void StartFrame();
  void EndFrame();
  void ClearScreen(RColor color = RColor::Black);

};

} // RBreakout::UI

#endif // RBREAKOUIT_ENTITY_H
