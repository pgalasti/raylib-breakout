#ifndef RBREAKOUT_LEVEL_H
#define RBREAKOUT_LEVEL_H

#include "core/EventBus.h"

#include <string_view>

namespace RBreakout::Core {

class Level {
public:

  Level(EventBus& eventBus);
  Level(EventBus& eventBus, const std::string_view filePath); // Constructor to load a file for layout
  virtual ~Level() = default;

  Level(const Level&) = delete;
  Level(Level&&) = delete;
  Level& operator=(const Level&) = delete;
  Level& operator=(Level&&) = delete;

  virtual void Initialize();
  virtual void Start();
  virtual void Reset();

protected:
  EventBus& m_EventBus;
};

} // RBreakout::Core

#endif // RBREAKOUT_LEVEL_H
