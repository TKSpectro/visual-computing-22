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
#include "data/data.event.h"
#include "data/data.eventSystem.h"

#include "logic/logic.commandSystem.h"

static void callback1(Data::Event& event)
{
    std::cout << "Callback1() called" << std::endl;
}

static void callback2(Data::Event& event)
{
    std::cout << "Callback2() called" << std::endl;
}

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

        Data::Event& event1 = Data::EventSystem::GetInstance().MakeEvent();
        event1.SetType(1);
        Data::EventSystem::GetInstance().Register(Data::Event::BTypeID(1), &callback1);
        Data::Event& event2 = Data::EventSystem::GetInstance().MakeEvent();
        event2.SetType(2);
        Data::EventSystem::GetInstance().Register(Data::Event::BTypeID(2), &callback2);

        Data::EventSystem::GetInstance().FireEvent(event1);

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

                Logic::CommandSystem& commandSystem = Logic::CommandSystem::GetInstance();
                // Instead of doing events here we dispath them to a function (callback) in the gui project
                // In there should be a fat switch case for Closed, MouseInput, Button Presses etc.
                // We also wont direclty handle this but just put in in a queue
                // default case should just get returned to the os
                if (event.type == sf::Event::KeyPressed)
                {
                    Logic::Command& command = commandSystem.CreateCommand();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                        command.SetType(Logic::CommandType::MoveUp);
                        commandSystem.AddCommand(command);
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                        command.SetType(Logic::CommandType::MoveDown);
                        commandSystem.AddCommand(command);
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                        command.SetType(Logic::CommandType::MoveLeft);
                        commandSystem.AddCommand(command);
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                        command.SetType(Logic::CommandType::MoveRight);
                        commandSystem.AddCommand(command);
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

        Data::EventSystem::GetInstance().Unregister(Data::Event::BTypeID(1), &callback1);
        Data::EventSystem::GetInstance().Unregister(Data::Event::BTypeID(2), &callback2);
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
