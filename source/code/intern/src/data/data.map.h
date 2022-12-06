#pragma once

#include "data.entityCategory.h"
#include "data.entityIterator.h"
#include "data.sector.h"

#include "../core/core_aabb.h"

namespace Data
{
    class Map
    {
    public:

        EntityIterator BeginEntity(Core::AABB2Float& AABB, EntityCategory::Enum category);
        EntityIterator NextEntity(EntityIterator where, Core::AABB2Float& AABB, EntityCategory::Enum category);

        EntityIterator BeginEntity(Core::AABB2Float& AABB);
        EntityIterator NextEntity(EntityIterator where, Core::AABB2Float& AABB);

        EntityIterator EndEntity();

    private:

        Sector sectors[4 * 8];        // Use constants or create dynamic array
    };
}

