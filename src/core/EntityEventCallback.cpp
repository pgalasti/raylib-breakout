#include "core/EntityEventCallback.h"

using namespace RBreakout::Core;

void EntityEventCallback::Register(const EntityID entityId, const EventCallbackFunc func) {
  m_EntityEventMap.emplace(entityId, func);
}

void EntityEventCallback::Deregister(const EntityID entityId) {
  m_EntityEventMap.erase(entityId);
}

const EventCallbackFunc& EntityEventCallback::Lookup(const EntityID entityId) const {
  const auto iter = m_EntityEventMap.find(entityId);

  if(iter == m_EntityEventMap.end()) {
    throw EntityEventCallback::NotFound{std::string("Unable to find entityId in callback lookup: " + std::to_string(entityId))};
  }

  return iter->second;
}
