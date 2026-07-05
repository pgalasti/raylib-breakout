#ifndef RBREAKOUT_ENTITY_EVENT_CALLBACK_H
#define RBREAKOUT_ENTITY_EVENT_CALLBACK_H

#include "core/Entity.h"
#include "core/Events.h"

#include <functional>
#include <unordered_map>

namespace RBreakout::Core {

using EventCallbackFunc = std::function<bool(Event*)>;
using EntityEventCallbackMap = std::unordered_map<EntityID, EventCallbackFunc>;

class EntityEventCallback {
public:

  void Register(const EntityID, const EventCallbackFunc func);
  void Deregister(const EntityID);

  const EventCallbackFunc& Lookup(const EntityID entityId) const;
 
  struct NotFound {
    std::string message;
  }; 
private:
  EntityEventCallbackMap m_EntityEventMap;

};

} // RBreakout::Core

#endif // RBREAKOUT_ENTITY_CALL_BACK_H
