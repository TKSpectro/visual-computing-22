#include "gfx.playPhase.h"

#include <vector>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <game/game.application.h>
#include <data/data.metaEntitySystem.h>
#include <data/data.entitySystem.h>
#include <data/data.playerSystem.h>

namespace Gfx
{
    void PlayPhase::OnEnter()
    {}

    bool PlayPhase::OnRun()
    {
        bool playerHitFinish = false;
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

            // We move the camera/view with the player entity
            if (entity->metaEntity->name == "player")
            {
                auto& prevSize = app.window.getView().getSize();

                sf::View view(sf::FloatRect(
                    entity->position[0] - prevSize.x / 2 + 128,
                    entity->position[1] - prevSize.y / 2 - 64 - 32,
                    prevSize.x,
                    prevSize.y
                ));

                app.window.setView(view);
            }

            if (entity->metaEntity->name == "finish")
            {
                Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
                Data::Entity* player = playerSystem.GetPlayer();

                playerHitFinish = player->aabb.Intersects(
                    Core::CAABB3<float>(
                        Core::Float3(entity->position[0], entity->position[1], entity->position[2]),
                        Core::Float3(entity->position[0] + 64, entity->position[1] + 64, entity->position[2])
                    )
                );;
            }
        }

        // end the current frame and display everything drawn
        app.window.display();

        return playerHitFinish;
    }

    void PlayPhase::OnLeave()
    {}
}
