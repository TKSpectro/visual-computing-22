#include <SFML/Graphics.hpp>
#include <cassert>

#include "core/core_time.h"

#include "game.application.h"
#include "game.phase.h"
#include "game.startupPhase.h"
#include "game.mainMenuPhase.h"
#include "game.loadPhase.h"
#include "game.playPhase.h"
#include "game.unloadPhase.h"
#include "game.shutdownPhase.h"

#include "data/data.playerSystem.h"

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

                if (event.type == sf::Event::Resized)
                {
                    // update the view to the new size of the windowl
                    sf::FloatRect visibleArea(0.f, 0.f, (float)event.size.width, (float)event.size.height);
                    window.setView(sf::View(visibleArea));
                }


                // Instead of doing events here we dispath them to a function (callback) in the gui project
                // In there should be a fat switch case for Closed, MouseInput, Button Presses etc.
                // We also wont direclty handle this but just put in in a queue
                // default case should just get returned to the os
                if (event.type == sf::Event::KeyPressed)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
                        Data::Entity* player = playerSystem.GetPlayer();
                        if (player != nullptr)
                        {
                            player->position = Core::Float3(player->position[0] - 2.0f, player->position[1], player->position[2]);
                        }

                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
                        Data::Entity* player = playerSystem.GetPlayer();
                        if (player != nullptr)
                        {
                            player->position = Core::Float3(player->position[0] + 2.0f, player->position[1], player->position[2]);
                        }
                    }
                }
            }

            // Core::RealTime::Update();
            // Core::LogicalTime::Update();

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

int main()
{
    Game::Application& application = Game::Application::GetInstance();

    application.Initialize();

    application.Run();

    application.Finalize();

    return 0;
}

//#include "data/data.eventListener.h"
//#include "data/data.eventSystem.h"
//
//static void myf(Data::Event& event)
//{
//    std::cout << "myf()" << std::endl;
//}
//
//static void myf2(Data::Event& event)
//{
//    std::cout << "myf2()" << std::endl;
//}
//
//class Listener
//{
//public:
//
//    static Listener& GetInstance()
//    {
//        static Listener instance;
//
//        return instance;
//    }
//
//public:
//
//    void Initialize()
//    {
//        Data::EventSystem::GetInstance().Register(Data::Event::BTypeID(1), &myf);
//        Data::EventSystem::GetInstance().Register(Data::Event::BTypeID(2), &myf2);
//    }
//
//    void Finalize()
//    {
//        Data::EventSystem::GetInstance().Unregister(Data::Event::BTypeID(1), &myf);
//        Data::EventSystem::GetInstance().Unregister(Data::Event::BTypeID(2), &myf2);
//    }
//
//private:
//
//    static void OnEventA(Data::Event& event)
//    {
//        GetInstance().DoSomethingA(event);
//    }
//
//    static void OnEventB(Data::Event& event)
//    {
//        GetInstance().DoSomethingB(event);
//    }
//
//private:
//
//    Listener() = default;
//    ~Listener() = default;
//
//private:
//
//    void DoSomethingA(Data::Event& event)
//    {
//        std::cout << "DoSomethingA()" << std::endl;
//    }
//
//    void DoSomethingB(Data::Event& event)
//    {
//        std::cout << "DoSomethingB()" << std::endl;
//    }
//
//private:
//
//    Listener(const Listener&) = delete;
//    Listener& operator = (const Listener&) = delete;
//};
//
//int main()
//{
//    Data::Event& event1 = Data::EventSystem::GetInstance().MakeEvent();
//    event1.SetType(1);
//    Data::EventSystem::GetInstance().Register(Data::Event::BTypeID(1), &myf);
//
//    Data::Event& event2 = Data::EventSystem::GetInstance().MakeEvent();
//    event2.SetType(2);
//    Data::EventSystem::GetInstance().Register(Data::Event::BTypeID(2), &myf2);
//
//
//    Data::EventSystem::GetInstance().FireEvent(event1);
//
//    Data::EventSystem::GetInstance().Unregister(Data::Event::BTypeID(1), &myf);
//    Data::EventSystem::GetInstance().Unregister(Data::Event::BTypeID(2), &myf2);
//
//    return 0;
//}

