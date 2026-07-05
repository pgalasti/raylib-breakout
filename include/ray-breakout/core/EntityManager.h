#ifndef RBREAKOUT_ENTITYMANAGER_H
#define RBREAKOUT_ENTITYMANAGER_H

#include "core/Entity.h"

#include <memory>
#include <unordered_map>
#include <functional>

namespace RBreakout::Core {

using EntityMap = std::unordered_map<EntityID, std::unique_ptr<Entity>>;

class EntityManager {
public:

  struct Options {
    size_t expectedRenderEntities {200};
  };

  EntityManager(const Options& options);


  // Should setup an emplace RegisterEntity in future
  EntityID RegisterEntity(const Point2Df& position, const EntityOptions& options = EntityOptions{});
  void UpdateEntity(const EntityID id, const Point2Df& position); // Need a more generic option.
  void DeregisterEntity(const EntityID id);

  const EntityList& GetRenderableEntities() const;

private:
  EntityMap m_EntityMap;
  EntityID nextId {0}; // I can use my ID Generator class in glibs but for now just use this.

  mutable EntityList m_EntityList; // Clear per frame and re-use this container for listing entities to render
};

} // RBreakout::Core

#endif // RBREAKOUT_ENTITYMANAGER_H
