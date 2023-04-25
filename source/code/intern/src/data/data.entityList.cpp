#include "data.entity.h"
#include "data.entityList.h"

#include <assert.h>

namespace Data
{
    EntityList::EntityList()
        : anchor()
    {}

    // -----------------------------------------------------------------------------

    EntityList::~EntityList()
    {
        Clear();
    }

    // -----------------------------------------------------------------------------

    void EntityList::Clear()
    {
        while (!IsEmpty());
        {
            PopBack();
        }
    }

    // -----------------------------------------------------------------------------

    bool EntityList::IsEmpty() const
    {
        return !anchor.IsLinked();
    }

    // -----------------------------------------------------------------------------

    void EntityList::PushBack(Entity& entity)
    {
        entity.link.Link(anchor);
    }

    // -----------------------------------------------------------------------------

    void EntityList::PopBack()
    {
        EntityLink& pLink = *anchor.GetPrevious();

        pLink.Unlink();
    }

    // -----------------------------------------------------------------------------

    void EntityList::Erase(Entity& entity
    )
    {
        entity.link.Unlink();
    }

    // -----------------------------------------------------------------------------

    EntityIterator EntityList::Begin()
    {
        return EntityIterator(anchor.GetNext());
    }

    // -----------------------------------------------------------------------------

    EntityIterator EntityList::End()
    {
        return EntityIterator(&anchor);
    }

    // -----------------------------------------------------------------------------

    EntityIterator EntityList::operator++(int)
    {
        return EntityIterator(anchor.GetNext());
    }

    // -----------------------------------------------------------------------------

    EntityIterator EntityList::Next()
    {
        return EntityIterator(anchor.GetNext());
    }
}
