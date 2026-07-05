#ifndef RBREAKOUT_EVENT_BUS_H
#define RBREAKOUT_EVENT_BUS_H

#include "core/Events.h"
#include "core/Entity.h"
#include "core/EntityEventCallback.h"

#include <queue>
#include <unordered_set>
#include <unordered_map>

namespace RBreakout::Core {

using EntitySet = std::unordered_set<EntityID>;	
using EntitySubscriptionMap = std::unordered_map<EventType, EntitySet>;

class EventBus {
public:

  EventBus(const EntityEventCallback& entityCallback);

  void Subscribe(const EntityID entityId, EventType eventType); 
  bool Unsubscribe(const EntityID entityId, EventType eventType);

  void QueueEvent(Event&& event);
  void InvokeEvents();

private:
  EntitySubscriptionMap m_EntitySubscriptionMap;
  // Ignoring priority for now, but could have specific event queue per pri
  std::queue<Event> m_EventQueue;
  const EntityEventCallback& m_EntityEventCallbackLookup;
};

} // RBReakout::Core

#endif // RBREAKOUT_EVENT_BUS_H
