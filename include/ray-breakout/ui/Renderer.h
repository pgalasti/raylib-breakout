#ifndef RBREAKOUT_RENDERER_H
#define RBREAKOUT_RENDERER_H

#include "ui/Colors.h"
#include "ui/Window.h"
#include "core/Entity.h"

namespace RBreakout::UI {

using namespace RBreakout::Core;

class Renderer {
public:
  Renderer(Window* pWindow);
  ~Renderer() = default;
  Renderer(const Renderer&) = delete;
  Renderer(Renderer&&) = delete;
  Renderer& operator=(const Renderer&) = delete;
  Renderer& operator=(Renderer&&) = delete;

  void StartFrame();
  void EndFrame();
  void ClearScreen(RColor color = RColor::Black);
  void Render(const EntityList& entities);

private:
  Window* m_pWindow;

  // Maybe make these configurable later
  static constexpr float m_VirtualWidth {800}, m_VirtualHeight{450};
};

} // RBreakout::UI

#endif // RBREAKOUIT_ENTITY_H
