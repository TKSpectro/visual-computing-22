#include "gfx.startupPhase.h"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "data/data.metaEntitySystem.h"

#include "game/game.application.h"

using namespace tinyxml2;

namespace Gfx
{
    void StartupPhase::OnEnter()
    {}

    void StartupPhase::OnRun(tinyxml2::XMLDocument& doc)
    {
        Data::MetaEntitySystem& metaEntitySystem = Data::MetaEntitySystem::GetInstance();

        XMLElement* metaEntities = doc.FirstChildElement("meta-entities");
        XMLElement* xmlMetaEntity = metaEntities->FirstChildElement("meta-entity");

        for (;;)
        {
            if (xmlMetaEntity == nullptr)
            {
                break;
            }

            auto id = metaEntitySystem.GetMetaEntityID(xmlMetaEntity->FindAttribute("name")->Value());
            Data::MetaEntity& metaEntity = metaEntitySystem.GetMetaEntity(id);

            XMLElement* graphicsElement = xmlMetaEntity->FirstChildElement("graphics");

            std::string texturePath = graphicsElement->FirstChildElement("texture")->FindAttribute("value")->Value();

            sf::Texture* texture = new sf::Texture();
            if (texture->loadFromFile("textures/" + texturePath))
            {
                metaEntity.facetes[Data::MetaEntity::FacetType::GraphicsFacet] = texture;
            }

            xmlMetaEntity = xmlMetaEntity->NextSiblingElement();
        }

    }

    void StartupPhase::OnLeave()
    {}
}
