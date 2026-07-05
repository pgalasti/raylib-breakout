#include "core/EventBus.h"

using namespace RBreakout::Core;

EventBus::EventBus(const EntityEventCallback& entityCallback)
  : m_EntityEventCallbackLookup {entityCallback}
{
}

void EventBus::Subscribe(const EntityID entityId, EventType eventType) {
  auto iter { m_EntitySubscriptionMap.find(eventType) };

  if(iter != m_EntitySubscriptionMap.end()) {
    iter->second.insert(entityId);
    return;
  }

  m_EntitySubscriptionMap.emplace(eventType, EntitySet {entityId});
}

bool EventBus::Unsubscribe(const EntityID entityId, EventType eventType) {
  auto iter { m_EntitySubscriptionMap.find(eventType) };

  if(iter == m_EntitySubscriptionMap.end()) {
    return false;
  }

  return iter->second.erase(entityId) == 1uz;
}

void EventBus::QueueEvent(Event&& event) {
  m_EventQueue.push(std::move(event));
}

void EventBus::InvokeEvents() {
  while(!m_EventQueue.empty()) {
    Event event { std::move(m_EventQueue.front()) };
    m_EventQueue.pop();
    
    const EventType eventType { event.first };
    auto iter { m_EntitySubscriptionMap.find(eventType) };

    if(iter == m_EntitySubscriptionMap.end()) {
      // How should we handle an event to nothing mapped?
      // Continue for now
      continue;
    }

    const EntitySet& set { iter->second };
    for(auto entityId : set) {
      const EventCallbackFunc& callback {m_EntityEventCallbackLookup.Lookup(entityId)};

      callback(&event);
    }
  }
}
