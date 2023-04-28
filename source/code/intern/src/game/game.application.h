#pragma once
#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>

#include "game.phase.h"

#include "data/data.event.h"

namespace Game
{
    class Application
    {
    public:
        static Application& GetInstance()
        {
            static Application instance;
            return instance;
        };

        Application(const Application&) = delete;
        Application& operator = (const Application&) = delete;

    private:
        Application();

    private:
        int indexOfCurrentPhase;
        Phase* phases[Phase::NumberOfTypes];

    public:
        sf::RenderWindow window;

    public:
        void Initialize();
        void Run();
        void Finalize();

    private:
        bool RunPhase();
    };
}