#include "data.entitySystem.h"

#include <tinyxml2.h>
#include <iostream>
#include <string>

#include "../core/core_aabb3.h"
#include "../core/core_explode.h"

#include "data.metaEntitySystem.h"
#include "data.playerSystem.h"

using namespace tinyxml2;

namespace Data
{
    int EntitySystem::Initialize(tinyxml2::XMLDocument& doc)
    {
        int entityCount = 0;

        Data::MetaEntitySystem& metaEntitySystem = Data::MetaEntitySystem::GetInstance();

        XMLElement* entities = doc.FirstChildElement("entities");
        XMLElement* xmlEntity = entities->FirstChildElement("entity");

        for (;;)
        {
            if (xmlEntity == nullptr)
            {
                break;
            }

            std::string name = xmlEntity->FindAttribute("name")->Value();

            std::string metaEntityName = xmlEntity->FindAttribute("meta-entity")->Value();
            auto id = metaEntitySystem.GetMetaEntityID(metaEntityName);
            Data::MetaEntity& metaEntity = metaEntitySystem.GetMetaEntity(id);

            XMLElement* dataElement = xmlEntity->FirstChildElement("data");

            auto type = atoi(dataElement->FirstChildElement("type")->FirstChild()->Value());
            auto sizeStrings = Core::Explode(dataElement->FirstChildElement("size")->FirstChild()->Value(), ';');
            auto positionStrings = Core::Explode(dataElement->FirstChildElement("position")->FirstChild()->Value(), ';');

            Entity& entity = CreateEntity(name);

            if (type >= EntityCategory::NumberOfMembers)
            {
                entity.category = EntityCategory::Undefined;
            } else
            {
                entity.category = EntityCategory::Enum(type);
            }

            entity.size = Core::Float3(
               std::stof(sizeStrings[0]),
               std::stof(sizeStrings[1]),
               std::stof(sizeStrings[2])
            );
            entity.position = Core::Float3(
               std::stof(positionStrings[0]),
               std::stof(positionStrings[1]),
               std::stof(positionStrings[2])
            );
            entity.aabb = Core::CAABB3<float>(
                Core::Float3(entity.position[0], entity.position[1], entity.position[2]),
                Core::Float3(entity.position[0] + entity.size[0], entity.position[1] + entity.size[1], entity.position[2] + entity.size[2])
            );

            entity.metaEntity = &metaEntity;

            if (metaEntity.name == "player")
            {
                Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
                playerSystem.SetPlayer(&entity);
            }

            entityCount++;
            xmlEntity = xmlEntity->NextSiblingElement();
        }

        return entityCount;
    }

    std::vector<Data::Entity*> EntitySystem::GetAllEntities()
    {
        return itemManager.GetAllItems();
    }

    Entity& EntitySystem::CreateEntity(std::string name)
    {
        Core::CIDManager::BID id = idManager.Register(name);

        Entity& entity = itemManager.CreateItem(id);
        entity.id = id;

        return entity;
    }

    void EntitySystem::DestroyEntity(Entity& entity)
    {
        itemManager.DestroyItem(entity.id);
    }

    void EntitySystem::DestroyAllEntities()
    {
        std::cout << "DATA::ENITITYSYSTEM::DestroyAllEntities Clearing " << idManager.GetNumberOfNames() << " Entities" << std::endl;

        itemManager.Clear();
        idManager.Clear();
    }

    Entity& EntitySystem::SearchEntity(std::string name)
    {
        return itemManager.GetItem(idManager.GetByName(name));
    }

    Entity& EntitySystem::GetEntity(Core::CIDManager::BID id)
    {
        return itemManager.GetItem(id);
    }

    bool EntitySystem::ContainsEntity(std::string name)
    {
        return idManager.ContainsName(name);
    }

    Core::CIDManager::BID EntitySystem::GetEntityID(std::string name)
    {
        return idManager.GetByName(name);
    }
}
