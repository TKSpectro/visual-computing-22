#include <tinyxml2.cpp>
#include <iostream>

#include "data.metaEntitySystem.h"

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

            MetaEntity& item = CreateMetaEntity(name);
            item.name = name;
            item.size = size;

            metaEntityCount++;

            metaEntity = metaEntity->NextSiblingElement();
        }

        return metaEntityCount;
    }

    MetaEntity& MetaEntitySystem::CreateMetaEntity(std::string name)
    {
        Core::CIDManager::BID id = idManager.Register(name);

        return itemManager.CreateItem(id);
    }

    void MetaEntitySystem::DestroyMetaEntity(MetaEntity& metaEntity)
    {
        throw std::logic_error("Not Implemented");
    }

    void MetaEntitySystem::DestoryAllMetaEntities()
    {
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
