#include "data.map.h"

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
        Core::AABB2Float someAABB;
        Map map;

        const EntityIterator endIterator = map.End();

        for (EntityIterator it = map.Begin(someAABB); it != endIterator; it.Next(someAABB))
        {
            // it->CallSomeMethod

            Entity& entity = *it;

            // entity.CallSomeMethod
        }
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


        return EntityIterator();
    }

    EntityIterator Map::Begin(Core::AABB2Float& aabb)
    {
        // Clamp this to int from float
        int sectorX = aabb.GetMin()[0] / 16;
        int sectorY = aabb.GetMin()[1] / 16;
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
        const int MIN_Y = sectorY;

        Sector sector = sectors[sectorY * 8 + sectorX];
        for (EntityFolder folder : sector.folders)
        {
            if (!folder.entities.IsEmpty())
            {
                for (EntityIterator ptr = folder.entities.begin(); ptr != folder.entities.end(); ptr.Next())
                {
                    // TODO: Figure out why this is not working
                    //Entity enti = ptr.link->GetEntity();

                }
            }
        }
        //   if list.notEmpty()
        //     for alle entitaeten in der liste
        //       if entity AABB intersects inputAABB
        //         return entityIterator;

        const int MAX_X = 7;
        const int MAX_Y = 7;

        sectorX += 1;
        if (sectorX > MAX_X)
        {
            sectorY += 1;
            sectorX = MIN_X;

            if (sectorY > MAX_Y)
            {
                // TODO: This should return a nullptr instead
                return EntityIterator();
            }
        }
        // keine enity in dem Sektor gefunden
        // sektor x++
        // if (sektor x++ > maxX)
        //   sektorY++
        //   sektorX = sectorXMin vom Anfang
        //   If( sectorY > maxY)
        //     return nullptr;

        return EntityIterator();
    }

    //EntityIterator Map::EndEntity()
    //{
    //    return EntityIterator();
    //}
}

