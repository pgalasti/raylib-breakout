#include "core/EntityManager.h"

#include <utility>

using namespace RBreakout::Core;

EntityManager::EntityManager(const EntityManager::Options& options) {
  m_EntityList.reserve(options.expectedRenderEntities);
}

EntityID EntityManager::RegisterEntity(const Point2Df& position, const EntityOptions& options/*={}*/) {
 
  const EntityID id {nextId++};	
  m_EntityMap.emplace(nextId, std::make_unique<Entity>(nextId, position));

  // We'll figure out options later
  return id;
}

void EntityManager::UpdateEntity(const EntityID id, const Point2Df& position) {
  auto iter {m_EntityMap.find(id)};

  if(iter != m_EntityMap.end()) {
    // Should we throw? 
    return;
  }

  iter->second->position = position;
}

void EntityManager::DeregisterEntity(const EntityID id) {
  m_EntityMap.erase(id);
}

const EntityList& EntityManager::GetRenderableEntities() const {
  m_EntityList.clear();

  for(const auto& [key, value] : m_EntityMap) {
    // Renderable filter here
    m_EntityList.push_back(*value);
  }

  return m_EntityList;
}
