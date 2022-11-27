#include <tinyxml2.cpp>
#include <iostream>

#include "data.metaEntitySystem.h"

using namespace tinyxml2;

int Data::MetaEntitySystem::Initialize(tinyxml2::XMLDocument& doc)
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

Data::MetaEntity& Data::MetaEntitySystem::CreateMetaEntity(std::string name)
{
    Core::CIDManager::BID id = idManager.Register(name);

    return itemManager.CreateItem(id);
}

void Data::MetaEntitySystem::DestroyMetaEntity(MetaEntity& metaEntity)
{
    // TODO
}

void Data::MetaEntitySystem::DestoryAllMetaEntities()
{
    itemManager.Clear();
    idManager.Clear();
}

Data::MetaEntity& Data::MetaEntitySystem::SearchMetaEntity(std::string name)
{
    return itemManager.GetItem(idManager.GetByName(name));
}
