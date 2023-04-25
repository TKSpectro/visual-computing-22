#include "data.map.h"

#include "data.entity.h"

namespace Data
{
    // Example for iterating over the whole map
    void all()
    {
        Map map;

        const EntityIterator endIterator = map.End();

        for (EntityIterator it = map.Begin(); it != endIterator; it.Next())
        {
            // it->CallSomeMethod

            Entity& entity = *it;

            // entity.CallSomeMethod
        }
    }

    // Example for iterating over specific area
    void area()
    {
        Core::AABB3Float someAABB;
        Map map;

        const EntityIterator endIterator = map.End();

        //for (EntityIterator it = map.Begin(someAABB); it != endIterator; it.Next(someAABB))
        //{
        //    // it->CallSomeMethod

        //    Entity& entity = *it;

        //    // entity.CallSomeMethod
        //}
    }



    //EntityIterator Map::BeginEntity(Core::AABB2Float& AABB, EntityCategory::Enum category)
    //{
    //    // Get first sector within AABB which contains an entity within the entity list of the given category
    //    // return iterator to this entity, otherwise return end iterator


    //    return EndEntity();
    //}

    //// -----------------------------------------------------------------------------

    //EntityIterator Map::NextEntity(EntityIterator where, Core::AABB2Float& AABB, EntityCategory::Enum category)
    //{
    //    return EndEntity();
    //}

    //// -----------------------------------------------------------------------------

    //EntityIterator Map::BeginEntity(Core::AABB2Float& AABB)
    //{
    //    return EndEntity();
    //}

    //// -----------------------------------------------------------------------------

    //EntityIterator Map::NextEntity(EntityIterator where, Core::AABB2Float& AABB)
    //{
    //    return EndEntity();
    //}

    //// -----------------------------------------------------------------------------

    EntityIterator Map::Begin()
    {
        return sectors[0].folders[0].entities.Begin();
    }

    EntityIterator Map::Begin(EntityCategory::Enum category)
    {
        for (Sector sector : sectors)
        {
            for (EntityFolder folder : sector.folders)
            {
                for (EntityIterator ptr = folder.entities.Begin(); ptr != folder.entities.End(); ptr.Next())
                {
                    if (ptr.link->GetEntity().category == category)
                    {
                        return ptr;
                    }
                }
            }
        }
    }

    EntityIterator Map::Begin(Core::AABB3Float& aabb)
    {
        // Clamp this to int from float
        int sectorX = aabb.GetMin()[0] / SECTOR_SIZE;
        int sectorY = aabb.GetMin()[1] / SECTOR_SIZE;
        if (aabb.GetMin()[0] < 1)
        {
            --sectorX;
        }
        if (aabb.GetMin()[1] < 1)
        {
            --sectorY;
        }
        if (sectorX < 0)
        {
            sectorX = 0;
        }
        if (sectorY < 0)
        {
            sectorY = 0;
        }

        const int MIN_X = sectorX;

        Sector sector = sectors[sectorY * 8 + sectorX];
        for (EntityFolder folder : sector.folders)
        {
            if (!folder.entities.IsEmpty())
            {
                for (EntityIterator ptr = folder.entities.Begin(); ptr != folder.entities.End(); ptr.Next())
                {
                    if (ptr.link != nullptr)
                    {
                        Entity& enti = ptr.link->GetEntity();
                        if (enti.aabb.Intersects(aabb))
                        {
                            return ptr;
                        }
                    }
                }
            }
        }

        sectorX += 1;
        if (sectorX >= MAX_SECTORS_X)
        {
            sectorY += 1;
            sectorX = MIN_X;

            if (sectorY >= MAX_SECTORS_Y)
            {
                return EntityIterator();
            }
        }

        return EntityIterator();
    }

    EntityIterator Map::End()
    {
        return EntityIterator();
    }

    EntityIterator& Map::Next(EntityIterator& current)
    {
        // TODO: Currently no idea how
        int sectorX = current.link->GetEntity().position[0] / SECTOR_SIZE;
        int sectorY = current.link->GetEntity().position[1] / SECTOR_SIZE;

        return *(new EntityIterator());
    }

    void Map::AddEntity(Entity& entity)
    {
        // If entity is outside of map, do not add it
        if (entity.position[0] < 0 || entity.position[1] < 0 || entity.position[0] >= MAX_SECTORS_X * SECTOR_SIZE || entity.position[1] >= MAX_SECTORS_Y * SECTOR_SIZE)
        {
            return;
        }

        int sectorX = entity.position[0] / SECTOR_SIZE;
        int sectorY = entity.position[1] / SECTOR_SIZE;

        Sector& sector = sectors[sectorY * 8 + sectorX];
        sector.folders[entity.category].entities.PushBack(entity);
    }

    void Map::RemoveEntity(Entity& entity)
    {
        if (entity.position[0] < 0 || entity.position[1] < 0 || entity.position[0] >= MAX_SECTORS_X * SECTOR_SIZE || entity.position[1] >= MAX_SECTORS_Y * SECTOR_SIZE)
        {
            return;
        }

        int sectorX = entity.position[0] / SECTOR_SIZE;
        int sectorY = entity.position[1] / SECTOR_SIZE;

        Sector& sector = sectors[sectorY * 8 + sectorX];

        for (EntityIterator ptr = sector.folders[entity.category].entities.Begin(); ptr != sector.folders[entity.category].entities.End(); ptr.Next())
        {
            if (&(ptr.link->GetEntity()) == &entity)
            {
                ptr.link->Unlink();

                // TODO: Not sure if i have to delete something here, but i probably have to
            }
        }

    }

    //EntityIterator Map::EndEntity()
    //{
    //    return EntityIterator();
    //}
}

