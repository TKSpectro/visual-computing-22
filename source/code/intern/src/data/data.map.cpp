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

        Sector sector = sectors[sectorY * 8 + sectorX];
        // ueber alle EntityFolder iterieren
        //   if list.notEmpty()
        //     for alle entitaeten in der liste
        //       if entity AABB intersects inputAABB
        //         return entityIterator;

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

