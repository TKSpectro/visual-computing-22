#pragma once

#include "data.entityLink.h"
#include "data.metaEntity.h"

#include <array>

#include "../core/core_vector3.h"
#include "../core/core_id_manager.h"

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

        void SetFacet(Facet type, void* facet);
        void* GetFacet(Facet type);

    public:

        Core::CIDManager::BID id;
        Core::CVector3<float> position;
        Core::CVector3<float> size;
        Core::CVector3<float> aabb;
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
