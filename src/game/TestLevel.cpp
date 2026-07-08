#include "game/TestLevel.h"

using namespace RBreakout::Game;

void TestLevel::Initialize() {
  Event createPlayerEvent { EventType::CreatePlayer, std::make_unique<CreatePlayerEvent>(Point2Df{360, 60}) };
  m_EventBus.QueueEvent(std::move(createPlayerEvent));
}

void TestLevel::Start() {
}
void TestLevel::Reset() {
}
