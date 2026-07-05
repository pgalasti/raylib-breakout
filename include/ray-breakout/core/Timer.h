#ifndef BREAKOUT_TIMER_H
#define BREAKOUT_TIMER_H

#include <raylib.h>

namespace RBreakout::Core {

class FrameTimer {
public:
  virtual ~FrameTimer(){}

  virtual double GetFrameTime() const = 0;
  virtual void   Tick()               = 0;
};

// Using raylib's implementation 
class RLFrameTimer : public FrameTimer {

  float m_LastTime {0.0f};

public:

  void Tick() override {
    m_LastTime = ::GetFrameTime();
  }

  double GetFrameTime() const override {
    return static_cast<double>(m_LastTime);
  }
};


} // RBreakout::Core

#endif // BREAKOUT_TIMER_H
