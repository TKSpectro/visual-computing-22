#pragma once
#include <iostream>

#include "game.phase.h"
#include <SFML/Graphics/RenderWindow.hpp>

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
        //std::array<Phase*, Phase::NumberOfTypes> m_pPhases;

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