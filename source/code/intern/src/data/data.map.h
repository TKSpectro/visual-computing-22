#pragma once

#include "data.entityCategory.h"
#include "data.entityIterator.h"
#include "data.sector.h"

#include <list>

#include "../core/core_aabb.h"

using floatList = std::list<float>;
using floatListIterator = floatList::iterator;

namespace Data
{
    class Map
    {
        // TODO: This needs to be a singleton and rename it to map system
    public:
        const static int SECTOR_SIZE = 16;
        const static int MAX_SECTORS_X = 8;
        const static int MAX_SECTORS_Y = 4;

    public:
        EntityIterator Begin();
        EntityIterator Begin(EntityCategory::Enum category);
        EntityIterator Begin(Core::AABB3Float& AABB);
        EntityIterator Begin(Core::AABB3Float& AABB, EntityCategory::Enum category);

        EntityIterator End();

        EntityIterator& Next(EntityIterator& where);
        EntityIterator& Next(EntityIterator& where, EntityCategory::Enum category);
        EntityIterator& Next(EntityIterator& where, Core::AABB3Float& AABB);
        EntityIterator& Next(EntityIterator& where, Core::AABB3Float& AABB, EntityCategory::Enum category);

        // The following ones are old and need to be removed
        //EntityIterator NextEntity(EntityIterator where, Core::AABB2Float& AABB, EntityCategory::Enum category);

        //EntityIterator BeginEntity(Core::AABB2Float& AABB);
        //EntityIterator NextEntity(EntityIterator where, Core::AABB2Float& AABB);

        //EntityIterator EndEntity();

        // GetAll alle in map
        // GetAllInAABB alle in bestimmten bereich
        //   Zuerst alle Sektoren raussuchen (unten links anfangen und dann rechts und dann nach oben (Zeilenweise)
        //   Durchlaeuft alle Folder und gibt alle Entities zurueck die im Bereich liegen
        //   Falls keine gefunden werden in dem Sektor, dann muss in den naechsten Sektor gesprungen werden
        //   Wenn wir eine Entity haben und bei wir die Category von der aktuellen Entity genommen und dann in dem Folder mit dem KategoryIndex++ der Folder wieder aufgerufen. Falls das alles leer ist nehmen wir den owner Sektor und gehen in den
        // GetAllInAABBWithCategory alle in bestimmten bereich mit bestimmten typ
        void GetExample(floatListIterator& begin, floatListIterator& end);
        // or
        std::pair<floatListIterator, floatListIterator> GetExample2();

        void AddEntity(Entity& entity);
        void RemoveEntity(Entity& entity);
        void MoveEntity(Entity& entity);
        // We need a AddEntity, RemoveEntity and MoveEntity
        // AddEntity checks where the entity is on the map and then decides in which sector/folder it should be placed
        // Remove is basically the same
        // MoveEntity calculates the new position  and then has to check if the it switched in sector and if so we have to remove it from the old list and add it to the new one

    private:

        Sector sectors[MAX_SECTORS_Y * MAX_SECTORS_X];
    };
}

