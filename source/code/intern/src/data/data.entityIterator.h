#pragma once

#include "../core/core_aabb2.h"

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

        EntityIterator& operator = (const EntityIterator& other);

        Entity& operator * ();
        Entity* operator -> ();

        bool operator == (const EntityIterator& other) const;
        bool operator != (const EntityIterator& other) const;

        //EntityIterator& operator ++ ();  // prefix
        //EntityIterator operator ++ (int);// postfix

        // Gleiche gibt es auch nochmal fuer Begin (alle 4 Varianten)
        // Callen immer nur die Next Methoden auf der Map auf
        EntityIterator& Next(); // Durch alle durch
        EntityIterator& Next(int category); // Check mit Category
        EntityIterator& Next(const Core::CAABB2<float>& AABB); // Check mit BoundingBox
        EntityIterator& Next(const Core::CAABB2<float>& AABB, int category); // Check mit Boundingbox und Category


    public:

        EntityLink* link;

    private:

        EntityIterator(EntityLink* link);

    private:

        friend class EntityList;
    };
}
