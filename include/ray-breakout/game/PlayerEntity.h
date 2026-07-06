#ifndef RBREAKOUT_PLAYER_ENTITY_H
#define RBREAKOUT_PLAYER_ENTITY_H

#include "core/Entity.h"

namespace RBreakout::Game {

using Core = RBreakout::Core;

class PlayerEntity : public Core::Entity {
public:
  PlayerEntity(const Core::EntityID id, const Point2Df& position) 
    : Entity(id, position) {}
private:

};

} // RBreakout::Game
 
#endif // RBREAKOUT_PLAYER_ENTITY_H
