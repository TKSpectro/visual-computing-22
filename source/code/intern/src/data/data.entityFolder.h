#pragma once

#include "data.entityList.h"

namespace Data
{
    class Entity;
    class Sector;
}

namespace Data
{
    class EntityFolder
    {
    public:

        void AddEntity(Entity& entity);
        void RemoveEntity(Entity& entity);

    public:

        Sector* owner;
        EntityList entities;
    };
}
