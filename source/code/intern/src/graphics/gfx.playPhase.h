#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

namespace Gfx
{
    class PlayPhase
    {
    public:
        static PlayPhase& GetInstance()
        {
            static PlayPhase instance;
            return instance;
        };

        PlayPhase(const PlayPhase&) = delete;
        PlayPhase& operator = (const PlayPhase&) = delete;

    public:
        void OnEnter();
        void OnRun();
        void OnLeave();

    private:
        PlayPhase()
        {};

    private:
        sf::Font font;
        sf::Text textPoints;
        sf::Text textTimer;
    };
}