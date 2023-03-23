#include "gfx.playPhase.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <game/game.application.h>
#include <data/data.metaEntitySystem.h>

namespace Gfx
{
    void PlayPhase::OnEnter()
    {}

    void PlayPhase::OnRun()
    {
        Game::Application& app = Game::Application::GetInstance();

        // This needs to be replaced by the actual entity system instead of meta entities
        Data::MetaEntitySystem& metaEntitySystem = Data::MetaEntitySystem::GetInstance();

        // clear the app.m_window with black color
        app.window.clear(sf::Color::Black);

        auto id = metaEntitySystem.GetMetaEntityID("ground_stone");
        Data::MetaEntity metaEntity = metaEntitySystem.GetMetaEntity(id);

        // parse metaEntity.facetes[0] from void* as sf::Texture*
        sf::Texture* texturePtr = static_cast<sf::Texture*>(metaEntity.facetes[0]);

        sf::Sprite sprite;
        sprite.setTexture(*texturePtr);

        sprite.setPosition(metaEntity.aabb.GetMin()[0], metaEntity.aabb.GetMin()[1]);
        sprite.setOrigin(0.0f, metaEntity.aabb.GetMax()[1]);

        // factor in the texture size
        float xScale = metaEntity.aabb.GetMax()[0] - metaEntity.aabb.GetMin()[0];
        float yScale = metaEntity.aabb.GetMax()[1] - metaEntity.aabb.GetMin()[1];

        if (texturePtr != nullptr)
        {
            //auto test = texturePtr->getSize();
            //sf::Texture test = &sprite.getTexture();
            //test
        }


        //factor in the texture size for scale (*texturePtr.
        //float xSpriteScale = xScale / sprite.getTexture().getSize().x;


        //sprite.setScale();
        app.window.draw(sprite);

        if (false)
        {
            // draw everything here...
            sf::CircleShape shape(50.0f, 5);
            shape.setFillColor(sf::Color::White);
            shape.setPosition(120.0f, 10.0f);
            app.window.draw(shape);

            // create an array of 3 vertices that define a triangle primitive
            sf::VertexArray triangle(sf::Triangles, 3);

            // define the position of the triangle's points
            triangle[0].position = sf::Vector2f(10.0f, 10.0f);
            triangle[1].position = sf::Vector2f(100.0f, 10.0f);
            triangle[2].position = sf::Vector2f(10.0f, 100.0f);

            // define the color of the triangle's points
            triangle[0].color = sf::Color::Red;
            triangle[1].color = sf::Color::Blue;
            triangle[2].color = sf::Color::Green;
            app.window.draw(triangle);
        }

        // end the current frame
        app.window.display();
    }

    void PlayPhase::OnLeave()
    {}
}
