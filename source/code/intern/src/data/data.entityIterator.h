#pragma once

namespace Data
{
    class Entity;
    class EntityLink;
    class EntityList;
}

namespace Data
{
    class EntityIterator
    {
    public:

        EntityIterator();
        EntityIterator(const EntityIterator& other);

    public:

        Entity& operator * ();
        Entity* operator -> ();

    private:

        EntityLink* link;

    private:

        EntityIterator(EntityLink* link);

    private:

        friend class EntityList;
    };
}
