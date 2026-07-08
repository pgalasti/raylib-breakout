#ifndef RBREAKOUT_EVENTS_H
#define RBREAKOUT_EVENTS_H

#include "core/Geometry.h"
#include "core/Entity.h"

#include <utility>
#include <memory>

namespace RBreakout::Core {

enum class EventType {
  PlayerMovement,
  CreatePlayer,
  EnableMovement
};

enum class EventPriority {
  High, Medium, Low
};

struct EventDetails {

  EventPriority priority;
  
  virtual ~EventDetails() = default;

protected:
  EventDetails(EventPriority priority) : priority {priority} {}
};

using Event = std::pair<EventType, std::unique_ptr<EventDetails>>;

struct MovementEvent : public EventDetails {
  MovementEvent(const Vector2Df& v, EventPriority priority = EventPriority::High) 
    : EventDetails(priority), vec {v} {}
  
  Vector2Df vec;
};

struct CreatePlayerEvent : public EventDetails {
  CreatePlayerEvent(const Point2Df& position) 
    : EventDetails{EventPriority::High}, startPosition{position} {}

  Point2Df startPosition; 
};

struct EnableMovementEvent : public EventDetails {
  EnableMovementEvent(const EntityID playerId)
    : EventDetails(EventPriority::High), playerId{playerId} {}

  EntityID playerId;
};

} // RBreakout::Core
#endif //RBREAKOUT_EVENTS_H
