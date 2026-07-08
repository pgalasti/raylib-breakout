#ifndef RBREAKOUT_ENTITY_H
#define RBREAKOUT_ENTITY_H

#include "core/Geometry.h"

#include <vector>

namespace RBreakout::Core {

using EntityID = unsigned int;


class Entity {
public:

  Entity(const EntityID id, const Point2Df& position, bool doRender = false)
    : id {id}, position {position}, doRender {doRender} {}

  Point2Df position;
  bool doRender;

protected:
  EntityID id;
};

struct EntityOptions {
  bool doRender{false};
};

using EntityList = std::vector<std::reference_wrapper<Core::Entity>>;

} // RBreakout::Core

#endif //RBREAKOUT_ENTITY_H
