#include "gfx.playPhase.h"

#include <vector>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <game/game.application.h>
#include <data/data.metaEntitySystem.h>

namespace Gfx
{
    void PlayPhase::OnEnter()
    {}

    void PlayPhase::OnRun()
    {
        Game::Application& app = Game::Application::GetInstance();

        // TODO: This needs to be replaced by the actual entity system instead of meta entities
        Data::MetaEntitySystem& metaEntitySystem = Data::MetaEntitySystem::GetInstance();

        // clear the app.m_window with black color
        app.window.clear(sf::Color::Black);

        auto id = metaEntitySystem.GetMetaEntityID("ground_stone");
        Data::MetaEntity metaEntity = metaEntitySystem.GetMetaEntity(id);

        auto id2 = metaEntitySystem.GetMetaEntityID("ground_stone2");
        Data::MetaEntity metaEntity2 = metaEntitySystem.GetMetaEntity(id2);

        std::vector<Data::MetaEntity> entities = { metaEntity, metaEntity2 };

        for (auto& entity : entities)
        {
            // parse metaEntity.facetes[0] from void* as sf::Texture*
            sf::Texture* texturePtr = static_cast<sf::Texture*>(entity.facetes[0]);

            sf::Sprite sprite;
            sprite.setTexture(*texturePtr);

            // TODO: This should be the entity position
            sprite.setPosition(entity.aabb.GetMin()[0], entity.aabb.GetMin()[1]);

            assert(texturePtr != nullptr);

            // factor in the texture size
            float xScale = entity.aabb.GetMax()[0] - entity.aabb.GetMin()[0];
            float yScale = entity.aabb.GetMax()[1] - entity.aabb.GetMin()[1];

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
