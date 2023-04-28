#include "data.entityIterator.h"

#include <assert.h>

#include "data.entityLink.h"

namespace Data
{
    EntityIterator::EntityIterator()
        : link(nullptr)
    {}

    EntityIterator::EntityIterator(const EntityIterator& other)
        : link(other.link)
    {}

    EntityIterator::EntityIterator(EntityLink* link)
        : link(link)
    {}

    Entity& EntityIterator::operator * ()
    {
        assert(link != nullptr);

        return link->GetEntity();
    }

    Entity* EntityIterator::operator -> ()
    {
        assert(link != nullptr);

        return &link->GetEntity();
    }

    bool EntityIterator::operator == (const EntityIterator& other) const
    {
        return link == other.link;
    }

    bool EntityIterator::operator != (const EntityIterator& other) const
    {
        return link != other.link;
    }

    //EntityIterator& EntityIterator::operator++()
    //{
    //    // TODO: These might be completely wrong
    //    if (link)
    //    {
    //        link = link->GetNext();
    //    }

    //    return *this;
    //}

    //EntityIterator EntityIterator::operator++(int)
    //{
    //    // TODO: These might be completely wrong
    //    return link->GetNext();
    //}

    //EntityIterator& EntityIterator::Next()
    //{
    //    return Data::MapSystem::GetInstance()->Next();
    //}

    //EntityIterator& EntityIterator::Next(int category)
    //{
    //    return Data::MapSystem::GetInstance()->Next(cat);
    //}

    //EntityIterator& EntityIterator::Next(const Core::CAABB2<float>& AABB)
    //{
    //    return Data::MapSystem::GetInstance()->Next(aabb);
    //}

    //EntityIterator& EntityIterator::Next(const Core::CAABB2<float>& AABB, int category)
    //{
    //    return Data::MapSystem::GetInstance()->Next(aabb, cat);
    //}

}
