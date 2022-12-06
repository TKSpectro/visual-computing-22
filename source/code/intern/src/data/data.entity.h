#pragma once

#include "data.entityLink.h"

#include <array>

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
