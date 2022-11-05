#pragma once
#include <iostream>

#include "phase.h"
#include <SFML/Graphics/RenderWindow.hpp>

namespace Game {
    class Application {
    public:
        static Application& GetInstance() {
            static Application instance;
            return instance;
        };

        Application(const Application&) = delete;
        Application& operator = (const Application&) = delete;

    private:
        Application();

    private:
        int m_IndexOfCurrentPhase;
        Phase* m_pPhases[Phase::NumberOfTypes];
        //std::array<Phase*, Phase::NumberOfTypes> m_pPhases;

    public:
        sf::RenderWindow m_window;

    public:
        void Initialize();
        void Run();

    private:
        bool RunPhase();
    };
}