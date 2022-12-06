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

    private:

        Sector* owner;
        EntityList entities;
    };
}
