#include "data.entityIterator.h"
#include "data.entityLink.h"

#include <assert.h>

namespace Data
{
    EntityIterator::EntityIterator()
        : link(nullptr)
    {}

    // -----------------------------------------------------------------------------

    EntityIterator::EntityIterator(const EntityIterator& other)
        : link(other.link)
    {}

    // -----------------------------------------------------------------------------

    EntityIterator::EntityIterator(EntityLink* link)
        : link(link)
    {}

    // -----------------------------------------------------------------------------

    Entity& EntityIterator::operator * ()
    {
        assert(link != nullptr);

        return link->GetEntity();
    }

    // -----------------------------------------------------------------------------

    Entity* EntityIterator::operator -> ()
    {
        assert(link != nullptr);

        return &link->GetEntity();
    }
}
