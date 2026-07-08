#include "core/Level.h"

using namespace RBreakout::Core;

Level::Level(EventBus& eventBus) : m_EventBus {eventBus} {

}

Level::Level(EventBus& eventBus, const std::string_view filePath) : Level(eventBus) {
  // Parse file
  // Read file
  // Create entities
}

void Level::Initialize() {
}

void Level::Start() {
}

void Level::Reset() {
}
