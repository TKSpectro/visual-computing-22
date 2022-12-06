#pragma once

#include "data.entityIterator.h"
#include "data.entityLink.h"

namespace Data
{
    class EntityList
    {
    public:

        EntityList();
        ~EntityList();

    public:

        void Clear();

        bool IsEmpty() const;

    public:

        void PushBack(Entity& entity);
        Entity& PopBack();

        void Erase(Entity& entity);

    public:

        EntityIterator Begin();
        EntityIterator End();

    private:

        EntityLink anchor;
    };
}
