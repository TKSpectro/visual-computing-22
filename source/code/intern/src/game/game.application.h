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

    private:
        static void callback1(Data::Event& event)
        {
            std::cout << "Callback1() called. Type: " << event.GetType() << std::endl;
            std::cout << "Callback1() called. Data: " << event.GetData() << std::endl;
        }

        static void callback2(Data::Event& event)
        {
            std::cout << "Callback2() called. Type: " << event.GetType() << std::endl;
            std::cout << "Callback2() called. Data: " << event.GetData() << std::endl;
        }

    public:
        void Initialize();
        void Run();
        void Finalize();

    private:
        bool RunPhase();
    };
}