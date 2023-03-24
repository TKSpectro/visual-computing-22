#include "gfx.startupPhase.h"

#include <iostream>
#include <tinyxml2.h>
#include <fstream>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <game/game.application.h>
#include <data/data.metaEntitySystem.h>

using namespace tinyxml2;

namespace Gfx
{
    void StartupPhase::OnEnter()
    {}

    void StartupPhase::OnRun(/*tinyxml2::XMLDocument& doc*/)
    {
        // TODO: Dont load the file again just get it passed through parameters
        XMLDocument doc;
        doc.LoadFile("../code/intern/src/data/data.meta-entity.xml");

        Game::Application& app = Game::Application::GetInstance();
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
            if (texture->loadFromFile(texturePath))
            {
                metaEntity.facetes[0] = texture;
            }

            xmlMetaEntity = xmlMetaEntity->NextSiblingElement();
        }

    }

    void StartupPhase::OnLeave()
    {}
}
