#include <tinyxml2.cpp>
#include <iostream>

#include "data.metaEntitySystem.h"

using namespace tinyxml2;

int Data::MetaEntitySystem::Initialize(tinyxml2::XMLDocument& doc)
{
    XMLElement* metaEntities = doc.FirstChildElement("meta-entities");

    int metaEntityCount = 0;
    XMLElement* metaEntity = metaEntities->FirstChildElement("meta-entity");
    for (;;)
    {
        if (metaEntity == nullptr)
        {
            break;
        }

        const char* name = metaEntity->FindAttribute("name")->Value();
        XMLElement* dataElement = metaEntity->FirstChildElement("data");
        float size = dataElement->FirstChildElement("size")->FindAttribute("value")->FloatValue();

        std::cout << "Name: " << name << std::endl;
        std::cout << "Size: " << size << std::endl;

        metaEntityCount++;

        metaEntity = metaEntity->NextSiblingElement();
    }

    return metaEntityCount;
}
