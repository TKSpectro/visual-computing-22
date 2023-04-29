#pragma once

#include <array>

#include "../core/core_vector3.h"
#include "../core/core_id_manager.h"

#include "data.entityLink.h"
#include "data.metaEntity.h"
#include "data.entityCategory.h"

namespace Data
{
    class EntityList;
}

namespace Data
{
    class Entity
    {
    public:

        enum Facet
        {
            GraphicsFacet,
            LogicFacet,
            NumberOfFacets
        };

    public:

        void SetFacet(Facet type, void* facet)
        {
            facets[type] = facet;
        }
        void* GetFacet(Facet type)
        {
            return facets[type];
        }

    public:

        Core::CIDManager::BID id;
        EntityCategory::Enum category;

        Core::CVector3<float> position;
        Core::CVector3<float> size;
        Core::CAABB3<float> aabb;
        MetaEntity* metaEntity;

    private:

        using FacetArray = std::array<void*, NumberOfFacets>;

    private:

        FacetArray facets;
        EntityLink link;

    private:

        friend class EntityLink;
        friend class EntityList;
    };
}
