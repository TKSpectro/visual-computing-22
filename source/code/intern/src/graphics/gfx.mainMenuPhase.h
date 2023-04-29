#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace Gfx
{
    class MainMenuPhase
    {
    public:
        static MainMenuPhase& GetInstance()
        {
            static MainMenuPhase instance;
            return instance;
        };

        MainMenuPhase(const MainMenuPhase&) = delete;
        MainMenuPhase& operator = (const MainMenuPhase&) = delete;

    public:
        void OnEnter();
        void OnRun();
        void OnLeave();

    private:
        MainMenuPhase()
        {};

    private:
        sf::Font font;
        sf::Text textMainMenu;
        sf::Text textButtons;
        sf::Text textMovement;
        sf::Text textHighscore;
        sf::Text textLastRunNewHighscore;
        sf::Text textInstructions;
        sf::Text textMapSelect;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;
    };
}