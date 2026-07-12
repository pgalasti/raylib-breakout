#ifndef RBREAKOUT_WINDOW_H
#define RBREAKOUT_WINDOW_H

#include "ui/Window.h"

#include <string>

namespace RBreakout::UI {

struct WindowOptions {
  int width {800};
  int height {450};
  int targetFps {120}; 
  std::string windowTitle;
};

class Window {
public:
  Window(const WindowOptions& options = WindowOptions{}) 
    : options {options} {}
  ~Window() = default;
  Window(const Window&) = delete;
  Window(Window&&) = delete;
  Window& operator=(const Window&) = delete;
  Window& operator=(Window&&) = delete;

  void Init();
  bool IsWindowOpen() const;
  void Shutdown();

  const WindowOptions& GetWindowOptions() const { return options; }
private:
  WindowOptions options;

};


}; // RBreakout namespace


#endif // RBREAKOUT_WINDOW_H
