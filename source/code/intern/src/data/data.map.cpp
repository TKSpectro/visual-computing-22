#include "data.map.h"

namespace Data
{
    EntityIterator Map::BeginEntity(Core::AABB2Float& AABB, EntityCategory::Enum category)
    {
        // Get first sector within AABB which contains an entity within the entity list of the given category
        // return iterator to this entity, otherwise return end iterator


        return EndEntity();
    }

    // -----------------------------------------------------------------------------

    EntityIterator Map::NextEntity(EntityIterator where, Core::AABB2Float& AABB, EntityCategory::Enum category)
    {
        return EndEntity();
    }

    // -----------------------------------------------------------------------------

    EntityIterator Map::BeginEntity(Core::AABB2Float& AABB)
    {
        return EndEntity();
    }

    // -----------------------------------------------------------------------------

    EntityIterator Map::NextEntity(EntityIterator where, Core::AABB2Float& AABB)
    {
        return EndEntity();
    }

    // -----------------------------------------------------------------------------

    EntityIterator Map::EndEntity()
    {
        return EntityIterator();
    }
}

