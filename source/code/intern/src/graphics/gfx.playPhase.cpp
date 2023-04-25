#include "gfx.playPhase.h"

#include <vector>
#include <iomanip>
#include <sstream>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <core/core_time.h>
#include <game/game.application.h>
#include <data/data.metaEntitySystem.h>
#include <data/data.entitySystem.h>
#include <data/data.playerSystem.h>
#include <data/data.pointSystem.h>

namespace Gfx
{
    void PlayPhase::OnEnter()
    {
        font.loadFromFile("roboto.ttf");

        textPoints.setFont(font);
        textPoints.setString("Points: 0");
        textPoints.setCharacterSize(48);
        textPoints.setFillColor(sf::Color::White);

        textTimer.setFont(font);
        textTimer.setString("Time: 0");
        textTimer.setCharacterSize(48);
        textTimer.setFillColor(sf::Color::White);
    }

    void PlayPhase::OnRun()
    {
        Game::Application& app = Game::Application::GetInstance();

        // clear the app.m_window with black color
        app.window.clear(sf::Color::Black);

        // draw all entities
        std::vector<Data::Entity*> entities = Data::EntitySystem::GetInstance().GetAllEntities();
        for (Data::Entity* entity : entities)
        {
            if (entity != nullptr)
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
                        entity->position[0] - prevSize.x / 2 + 32,
                        entity->position[1] - prevSize.y / 2 + 32,
                        prevSize.x,
                        prevSize.y
                    ));

                    app.window.setView(view);
                }
            }
        }

        // draw the points
        textPoints.setString("Points: " + std::to_string(Data::PointSystem::GetInstance().GetPoints()));
        textPoints.setPosition(app.window.getView().getCenter().x - app.window.getView().getSize().x / 2, app.window.getView().getCenter().y - app.window.getView().getSize().y / 2);
        app.window.draw(textPoints);

        // draw the timer
        std::stringstream timeStream;
        timeStream << std::fixed << std::setprecision(2) << Core::Time::GetTime();
        textTimer.setString("Time: " + timeStream.str() + "s");
        textTimer.setPosition(app.window.getView().getCenter().x + app.window.getView().getSize().x / 2 - textTimer.getGlobalBounds().width - 12, app.window.getView().getCenter().y - app.window.getView().getSize().y / 2);
        app.window.draw(textTimer);

        // end the current frame and display everything drawn
        app.window.display();
    }

    void PlayPhase::OnLeave()
    {}
}
