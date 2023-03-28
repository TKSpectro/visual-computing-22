#include "gfx.mainMenuPhase.h"

#include <SFML/Graphics/Text.hpp>

#include <game/game.application.h>

namespace Gfx
{
    void MainMenuPhase::OnEnter()
    {
        Game::Application& app = Game::Application::GetInstance();
        auto& prevSize = app.window.getView().getSize();

        sf::View view(sf::FloatRect(
            0.0f,
            0.0f,
            prevSize.x,
            prevSize.y
        ));

        app.window.setView(view);

        font.loadFromFile("roboto.ttf");

        textMainMenu.setFont(font);
        textMainMenu.setString("MAIN MENU");
        textMainMenu.setCharacterSize(48);
        textMainMenu.setFillColor(sf::Color::White);

        textButtons.setFont(font);
        textButtons.setString("Start: Enter\nClose: Escape");
        textButtons.setCharacterSize(32);
        textButtons.setFillColor(sf::Color::White);
        textButtons.setPosition(0, textMainMenu.getGlobalBounds().height + 32);

        textMovement.setFont(font);
        textMovement.setString("Movement: Arrow Keys");
        textMovement.setCharacterSize(32);
        textMovement.setFillColor(sf::Color::White);
        textMovement.setPosition(0, textButtons.getPosition().y + textButtons.getGlobalBounds().height + 32);
    }

    void MainMenuPhase::OnRun()
    {
        Game::Application& app = Game::Application::GetInstance();

        app.window.clear(sf::Color::Black);

        app.window.draw(textMainMenu);
        app.window.draw(textButtons);
        app.window.draw(textMovement);

        app.window.display();
    }

    void MainMenuPhase::OnLeave()
    {}
}
