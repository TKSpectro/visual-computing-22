#include "game.playPhase.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>

#include "game.application.h"

namespace Game
{
    int PlayPhase::InternOnEnter()
    {
        std::cout << "GAME::PLAY::Enter" << std::endl;

        //data::PlayPhase::OnRun()
        //logic::PlayPhase::OnRun()
        //gfx::PlayPhase::OnRun()
        //gui::PlayPhase::OnRun()

        return 0;
    }

    int PlayPhase::InternOnRun()
    {
        if (counter % 100 == 0)
        {
            std::cout << "GAME::PLAY::Run::" << counter << std::endl;
        }

        counter++;
        if (counter > 2000)
        {
            return Type::UNLOAD_MAP;
        }

        Application& app = Application::GetInstance();

        // clear the app.m_window with black color
        app.window.clear(sf::Color::Black);

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

        // end the current frame
        app.window.display();

        return Type::PLAY;
    }

    int PlayPhase::InternOnLeave()
    {
        std::cout << "GAME::PLAY::Leave" << std::endl;

        return 0;
    }
}
