#include <SFML/Graphics.hpp>
#include <cassert>

#include "game.application.h"
#include "game.phase.h"
#include "game.startupPhase.h"
#include "game.mainMenuPhase.h"
#include "game.loadPhase.h"
#include "game.playPhase.h"
#include "game.unloadPhase.h"
#include "game.shutdownPhase.h"

namespace Game
{
    Application::Application()
        : indexOfCurrentPhase(Phase::Undefined),
        phases{
        &StartupPhase::GetInstance(),
        &MainMenuPhase::GetInstance(),
        &LoadPhase::GetInstance(),
        &PlayPhase::GetInstance(),
        &UnloadPhase::GetInstance(),
        &ShutdownPhase::GetInstance()
        }
    {

    }

    void Application::Initialize()
    {
        std::cout << "GAME::APPLICATION::Initialize" << std::endl;

        // Enable fancy anitaliasing
        sf::ContextSettings settings;
        settings.antialiasingLevel = 8;

        window.create(sf::VideoMode(800, 450), "vc22 - Tom Kaeppler", sf::Style::Default, settings);
        std::cout << "GAME::APPLICATION::Initialize Window created" << std::endl;

        indexOfCurrentPhase = Phase::STARTUP;
        phases[indexOfCurrentPhase]->OnEnter();
    }

    void Application::Run()
    {
        std::cout << "GAME::APPLICATION::Run" << std::endl;

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        for (;;)
        {
            if (window.isOpen() == false)
            {
                break;
            }

            while (window.pollEvent(event))
            {
                // "close requested" event: we close the m_window
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }

            if (RunPhase() == false)
            {
                break;
            }
        }
    }

    void Application::Finalize()
    {
        std::cout << "GAME::APPLICATION::Finalize" << std::endl;
    }

    bool Application::RunPhase()
    {
        Phase* currentPhase = phases[indexOfCurrentPhase];
        assert(currentPhase != nullptr);

        int indexOfNextPhase = currentPhase->OnRun();

        if (indexOfNextPhase != indexOfCurrentPhase)
        {
            currentPhase->OnLeave();

            if (indexOfCurrentPhase == Phase::SHUTDOWN)
            {
                return false;
            }

            indexOfCurrentPhase = indexOfNextPhase;

            currentPhase = phases[indexOfCurrentPhase];

            assert(currentPhase != nullptr);

            currentPhase->OnEnter();
        }

        return true;
    }

}

//int main()
//{
//    Game::Application& application = Game::Application::GetInstance();
//
//    application.Initialize();
//
//    application.Run();
//
//    application.Finalize();
//
//    return 0;
//}


#include "data/data.eventListener.h"
#include "data/data.eventSystem.h"

class Listener
{
public:

    static Listener& GetInstance()
    {
        static Listener instance;

        return instance;
    }

public:

    void Initialize()
    {
        Data::EventSystem::GetInstance().Register(0, Listener::OnEventA);
        Data::EventSystem::GetInstance().Register(1, Listener::OnEventB);
    }

    void Finalize()
    {
        Data::EventSystem::GetInstance().Unregister(0, Listener::OnEventA);
        Data::EventSystem::GetInstance().Unregister(1, Listener::OnEventB);
    }

private:

    static void OnEventA(Data::Event& event)
    {
        Listener::GetInstance().DoSomethingA(event);
    }

    static void OnEventB(Data::Event& event)
    {
        Listener::GetInstance().DoSomethingB(event);
    }

private:

    Listener() = default;
    ~Listener() = default;

private:

    void DoSomethingA(Data::Event& event)
    {
        std::cout << "DoSomethingA()" << std::endl;
    }

    void DoSomethingB(Data::Event& event)
    {
        std::cout << "DoSomethingB()" << std::endl;
    }

private:

    Listener(const Listener&) = delete;
    Listener& operator = (const Listener&) = delete;
};

int main()
{
    Data::Event event1 = Data::EventSystem::GetInstance().MakeEvent();
    //event1.SetType(1);

    Data::Event event2 = Data::EventSystem::GetInstance().MakeEvent();
    //event2.SetType(2);

    Listener::GetInstance().Initialize();

    Listener::GetInstance().Finalize();

    return 0;
}

