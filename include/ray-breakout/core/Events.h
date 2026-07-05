#ifndef RBREAKOUT_EVENTS_H
#define RBREAKOUT_EVENTS_H

namespace RBreakout::Core {

enum class EventType {
  Movement
};

struct MovementEvent {
  Event type;
};

} // RBreakout::Core
#endif //RBREAKOUT_EVENTS_H
