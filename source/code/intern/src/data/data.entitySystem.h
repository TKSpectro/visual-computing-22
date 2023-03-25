#pragma once
#include <tinyxml2.h>

#include "../core/core_id_manager.h"
#include "../core/core_item_manager.h"
#include "data.Entity.h"

namespace Data
{
    class EntitySystem
    {
    public:
        static EntitySystem& GetInstance()
        {
            static EntitySystem instance;
            return instance;
        };

        EntitySystem(const EntitySystem&) = delete;
        EntitySystem& operator = (const EntitySystem&) = delete;

    public:
        int Initialize(tinyxml2::XMLDocument& doc);
        std::vector<Data::Entity*> GetAllEntities();
        Entity& CreateEntity(std::string name);
        void DestroyEntity(Entity& entity);
        void DestoryAllEntities();
        Entity& SearchEntity(std::string name);
        Entity& GetEntity(Core::CIDManager::BID id);
        bool ContainsEntity(std::string name);
        Core::CIDManager::BID GetEntityID(std::string name);

    private:
        EntitySystem()
        {};

    private:
        Core::CIDManager idManager;
        Core::CItemManager<Entity> itemManager;
    };
}