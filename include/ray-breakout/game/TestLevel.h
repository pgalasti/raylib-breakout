#ifndef RBREAKOUT_TEST_LEVEL_H
#define RBREAKOUT_TEST_LEVEL_H

#include "core/Level.h"

namespace RBreakout::Game {

using namespace RBreakout::Core;

class TestLevel : public Level {
public:
  TestLevel(EventBus& eventBus) : Level(eventBus) {}
  ~TestLevel() = default;

  void Initialize() override; 
  void Start() override; 
  void Reset() override; 

};

} // RBreakout::Game

#endif // RBREAKOUT_TEST_LEVEL_H
