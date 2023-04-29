#include "gfx.mainMenuPhase.h"

#include <fstream>
#include <iomanip>
#include <sstream>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <game/game.application.h>

#include <data/data.highscoreSystem.h>
#include <data/data.mapPickerSystem.h>

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

        // Load repeated background texture
        backgroundTexture.loadFromFile("images/background.png");
        backgroundTexture.setRepeated(true); // repeat tile over sprite height
        sf::IntRect iBounds(0, 0, 1000, 1000);
        backgroundSprite = sf::Sprite(backgroundTexture, iBounds);
        backgroundSprite.setPosition((float)iBounds.left, (float)iBounds.top - 1000.0f + app.GetInstance().window.getView().getSize().y);

        font.loadFromFile("fonts/roboto.ttf");

        textMainMenu.setFont(font);
        textMainMenu.setString("TURTLE MAZE");
        textMainMenu.setCharacterSize(48);
        textMainMenu.setFillColor(sf::Color::Black);
        // center the text horizontally
        textMainMenu.setPosition((app.window.getSize().x - textMainMenu.getGlobalBounds().width) / 2, 0);

        float xOffset = 32.0f;
        unsigned int fontSize = 32;

        Data::HighscoreSystem& highscoreSystem = Data::HighscoreSystem::GetInstance();

        if (highscoreSystem.TryReadHighscore())
        {
            std::stringstream timeStream;
            timeStream << std::fixed << std::setprecision(2) << highscoreSystem.GetTime();
            textHighscore.setString("Highscore: " + std::to_string(highscoreSystem.GetPoints()) + " points in " + timeStream.str() + " seconds");
        } else
        {
            textHighscore.setString("No Highscore set! Be the first one!");
        }

        if (highscoreSystem.GetLastRunNewHighscore())
        {
            textLastRunNewHighscore.setString("YOUR LAST RUN WAS A NEW HIGHSCORE!");
        } else
        {
            textLastRunNewHighscore.setString("");
        }

        textHighscore.setFont(font);
        textHighscore.setCharacterSize(fontSize);
        textHighscore.setFillColor(sf::Color::Black);
        textHighscore.setPosition((app.window.getSize().x - textHighscore.getGlobalBounds().width) / 2, textMainMenu.getPosition().y + textMainMenu.getGlobalBounds().height + fontSize);

        textLastRunNewHighscore.setFont(font);
        textLastRunNewHighscore.setCharacterSize(fontSize);
        textLastRunNewHighscore.setFillColor(sf::Color::Black);
        textLastRunNewHighscore.setPosition((app.window.getSize().x - textLastRunNewHighscore.getGlobalBounds().width) / 2, textHighscore.getPosition().y + textHighscore.getGlobalBounds().height + fontSize);

        textMapSelect.setFont(font);
        textMapSelect.setString("Selected Map:");
        textMapSelect.setCharacterSize(fontSize);
        textMapSelect.setFillColor(sf::Color::Black);
        textMapSelect.setPosition(xOffset, textLastRunNewHighscore.getPosition().y + textLastRunNewHighscore.getGlobalBounds().height + fontSize);

        textInstructions.setFont(font);
        textInstructions.setString("Instructions:");
        textInstructions.setCharacterSize(fontSize);
        textInstructions.setFillColor(sf::Color::Black);
        textInstructions.setPosition(xOffset, textMapSelect.getPosition().y + textMapSelect.getGlobalBounds().height + fontSize);

        textButtons.setFont(font);
        textButtons.setString("Start: Enter\nClose: Escape");
        textButtons.setCharacterSize(fontSize);
        textButtons.setFillColor(sf::Color::Black);
        textButtons.setPosition(xOffset, textInstructions.getPosition().y + textInstructions.getGlobalBounds().height + fontSize);

        textMovement.setFont(font);
        textMovement.setString("Movement: Arrow Keys or WASD");
        textMovement.setCharacterSize(fontSize);
        textMovement.setFillColor(sf::Color::Black);
        textMovement.setPosition(xOffset, textButtons.getPosition().y + textButtons.getGlobalBounds().height + fontSize);
    }

    void MainMenuPhase::OnRun()
    {
        Game::Application& app = Game::Application::GetInstance();

        app.window.clear(sf::Color::Black);

        app.window.draw(backgroundSprite);

        app.window.draw(textMainMenu);
        app.window.draw(textHighscore);
        app.window.draw(textLastRunNewHighscore);

        textMapSelect.setString("Selected Map: " + std::to_string(Data::MapPickerSystem::GetInstance().GetMapIndex() + 1));
        app.window.draw(textMapSelect);

        app.window.draw(textInstructions);
        app.window.draw(textButtons);
        app.window.draw(textMovement);

        app.window.display();
    }

    void MainMenuPhase::OnLeave()
    {}
}
