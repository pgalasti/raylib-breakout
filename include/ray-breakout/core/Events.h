#ifndef RBREAKOUT_EVENTS_H
#define RBREAKOUT_EVENTS_H

#include "core/Geometry.h"

#include <utility>
#include <memory>

namespace RBreakout::Core {

enum class EventType {
  PlayerMovement
};

enum class EventPriority {
  High, Medium, Low
};

struct EventDetails {

  EventPriority priority;
  
  ~EventDetails() = default;

protected:
  EventDetails(EventPriority priority) : priority {priority} {}
};

using Event = std::pair<EventType, std::unique_ptr<EventDetails>>;

struct MovementEvent : public EventDetails {
  MovementEvent(const Vector2Df& v, EventPriority priority = EventPriority::High) 
    : EventDetails(priority), vec {v} {}
  
  Vector2Df vec;
};

} // RBreakout::Core
#endif //RBREAKOUT_EVENTS_H
