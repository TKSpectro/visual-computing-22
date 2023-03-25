#include "gfx.playPhase.h"

#include <vector>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <game/game.application.h>
#include <data/data.metaEntitySystem.h>
#include <data/data.entitySystem.h>

namespace Gfx
{
    void PlayPhase::OnEnter()
    {}

    void PlayPhase::OnRun()
    {
        Game::Application& app = Game::Application::GetInstance();

        // TODO: This needs to be replaced by the actual entity system instead of meta entities
        Data::MetaEntitySystem& metaEntitySystem = Data::MetaEntitySystem::GetInstance();

        Data::EntitySystem& entitySystem = Data::EntitySystem::GetInstance();
        auto entities = entitySystem.GetAllEntities();

        // clear the app.m_window with black color
        app.window.clear(sf::Color::Black);

        for (auto& entity : entities)
        {
            sf::Texture* texturePtr = static_cast<sf::Texture*>(entity->metaEntity->facetes[0]);

            sf::Sprite sprite;
            sprite.setTexture(*texturePtr);

            sprite.setPosition(entity->position[0], entity->position[1]);

            assert(texturePtr != nullptr);

            // factor in the texture size
            float xScale = entity->metaEntity->aabb.GetMax()[0] - entity->metaEntity->aabb.GetMin()[0];
            float yScale = entity->metaEntity->aabb.GetMax()[1] - entity->metaEntity->aabb.GetMin()[1];

            float xSpriteScale = xScale / texturePtr->getSize().x;
            float ySpriteScale = yScale / texturePtr->getSize().y;

            sprite.setScale(xSpriteScale, ySpriteScale);

            app.window.draw(sprite);
        }

        // end the current frame and display everything drawn
        app.window.display();
    }

    void PlayPhase::OnLeave()
    {}
}
