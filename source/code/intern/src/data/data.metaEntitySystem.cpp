#include "data.metaEntitySystem.h"

#include <iostream>
#include <string>

#include "../core/core_aabb3.h"
#include "../core/core_explode.h"

using namespace tinyxml2;

namespace Data
{
    int MetaEntitySystem::Initialize(tinyxml2::XMLDocument& doc)
    {
        int metaEntityCount = 0;

        XMLElement* metaEntities = doc.FirstChildElement("meta-entities");
        XMLElement* metaEntity = metaEntities->FirstChildElement("meta-entity");

        for (;;)
        {
            if (metaEntity == nullptr)
            {
                break;
            }

            std::string name = metaEntity->FindAttribute("name")->Value();

            XMLElement* dataElement = metaEntity->FirstChildElement("data");
            float size = dataElement->FirstChildElement("size")->FindAttribute("value")->FloatValue();

            auto minCornerStrings = Core::Explode(dataElement->FirstChildElement("aabb")->FindAttribute("minCorner")->Value(), ';');
            auto maxCornerStrings = Core::Explode(dataElement->FirstChildElement("aabb")->FindAttribute("maxCorner")->Value(), ';');

            Core::AABB3Float aabb = Core::AABB3Float(
                Core::Float3(
                    std::stof(minCornerStrings[0]),
                    std::stof(minCornerStrings[1]),
                    std::stof(minCornerStrings[2])
                ),
                Core::Float3(
                    std::stof(maxCornerStrings[0]),
                    std::stof(maxCornerStrings[1]),
                    std::stof(maxCornerStrings[2])
                )
            );

            MetaEntity& entity = CreateMetaEntity(name);
            entity.name = name;
            entity.size = size;
            entity.aabb = aabb;

            metaEntityCount++;
            //std::cout << "MetaEntity: " << entity << std::endl;

            metaEntity = metaEntity->NextSiblingElement();
        }

        return metaEntityCount;
    }

    MetaEntity& MetaEntitySystem::CreateMetaEntity(std::string name)
    {
        Core::CIDManager::BID id = idManager.Register(name);

        return itemManager.CreateItem(id);
    }

    void MetaEntitySystem::DestroyAllMetaEntities()
    {
        std::cout << "DATA::ENITITYSYSTEM::DestroyAllMetaEntities Clearing " << idManager.GetNumberOfNames() << " Entities" << std::endl;

        itemManager.Clear();
        idManager.Clear();
    }

    MetaEntity& MetaEntitySystem::SearchMetaEntity(std::string name)
    {
        return itemManager.GetItem(idManager.GetByName(name));
    }

    MetaEntity& MetaEntitySystem::GetMetaEntity(Core::CIDManager::BID id)
    {
        return itemManager.GetItem(id);
    }

    bool MetaEntitySystem::ContainsMetaEntity(std::string name)
    {
        return idManager.ContainsName(name);
    }

    Core::CIDManager::BID MetaEntitySystem::GetMetaEntityID(std::string name)
    {
        return idManager.GetByName(name);
    }
}
