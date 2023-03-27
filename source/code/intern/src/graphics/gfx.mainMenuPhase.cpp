#include "gfx.mainMenuPhase.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <game/game.application.h>

namespace Gfx
{
    void MainMenuPhase::OnEnter()
    {
        Game::Application& app = Game::Application::GetInstance();

        texture.loadFromFile("mainmenu.png");
        sprite.setTexture(texture);

        sprite.setScale(
           (float)app.window.getSize().x / (float)texture.getSize().x,
           (float)app.window.getSize().y / (float)texture.getSize().y
        );
    }

    void MainMenuPhase::OnRun()
    {
        Game::Application& app = Game::Application::GetInstance();

        app.window.clear(sf::Color::Black);

        app.window.draw(sprite);

        app.window.display();
    }

    void MainMenuPhase::OnLeave()
    {}
}
