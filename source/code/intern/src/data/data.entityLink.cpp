#include "data.entity.h"
#include "data.entityLink.h"

#include <stdlib.h>

namespace Data
{
    Entity& EntityLink::GetEntity(EntityLink& link, const EntityLink Entity::* mtr)
    {
        return *reinterpret_cast<Entity*>(reinterpret_cast<ptrdiff_t>(&link) - (reinterpret_cast<ptrdiff_t>(&(static_cast<Entity*>(nullptr) ->*(mtr))) - reinterpret_cast<ptrdiff_t>(static_cast<void*>(nullptr))));
    }

    // -----------------------------------------------------------------------------

    const Entity& EntityLink::GetEntity(const EntityLink& link, const EntityLink Entity::* mtr)
    {
        return *reinterpret_cast<Entity*>(reinterpret_cast<ptrdiff_t>(&link) - (reinterpret_cast<ptrdiff_t>(&(static_cast<Entity*>(nullptr) ->*(mtr))) - reinterpret_cast<ptrdiff_t>(static_cast<void*>(nullptr))));
    }
}

namespace Data
{
    EntityLink::EntityLink()
    {
        next = this;
        previous = this;
    }

    // -----------------------------------------------------------------------------

    void EntityLink::Link(EntityLink& nextLink)
    {
        next = &nextLink;
        previous = nextLink.previous;

        nextLink.previous->next = this;
        nextLink.previous = this;
    }

    // -----------------------------------------------------------------------------

    void EntityLink::Unlink()
    {
        previous->next = next;
        next->previous = previous;

        next = this;
        previous = this;
    }

    // -----------------------------------------------------------------------------

    bool EntityLink::IsLinked() const
    {
        return next != next->next;
    }

    // -----------------------------------------------------------------------------

    Entity& EntityLink::GetEntity()
    {
        return GetEntity(*this, &Entity::link);
    }

    // -----------------------------------------------------------------------------

    const Entity& EntityLink::GetEntity() const
    {
        return EntityLink::GetEntity(*this, &Entity::link);
    }

    // -----------------------------------------------------------------------------

    void EntityLink::SetNext(EntityLink* link)
    {
        next = link;
    }

    // -----------------------------------------------------------------------------

    EntityLink* EntityLink::GetNext()
    {
        return next;
    }

    // -----------------------------------------------------------------------------

    void EntityLink::SetPrevious(EntityLink* link)
    {
        previous = link;
    }

    // -----------------------------------------------------------------------------

    EntityLink* EntityLink::GetPrevious()
    {
        return previous;
    }
}
