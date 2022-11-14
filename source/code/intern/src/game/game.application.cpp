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
        : m_IndexOfCurrentPhase(Phase::Undefined),
        m_pPhases{
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
        std::cout << "[APPLICATION] Initialize" << std::endl;

        // Enable fancy anitaliasing
        sf::ContextSettings settings;
        settings.antialiasingLevel = 8;

        m_window.create(sf::VideoMode(800, 450), "vc22 - Tom Kaeppler", sf::Style::Default, settings);
        std::cout << "[APPLICATION] Window created" << std::endl;

        m_IndexOfCurrentPhase = Phase::STARTUP;
        m_pPhases[m_IndexOfCurrentPhase]->OnEnter();
    }

    void Application::Run()
    {
        std::cout << "[APPLICATION] Run" << std::endl;

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        for (;;)
        {
            if (m_window.isOpen() == false)
            {
                break;
            }

            while (m_window.pollEvent(event))
            {
                // "close requested" event: we close the m_window
                if (event.type == sf::Event::Closed)
                {
                    m_window.close();
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
        std::cout << "[APPLICATION] Finalize" << std::endl;
    }

    bool Application::RunPhase()
    {
        Phase* pCurrentPhase = m_pPhases[m_IndexOfCurrentPhase];
        assert(pCurrentPhase != nullptr);

        int indexOfNextPhase = pCurrentPhase->OnRun();

        if (indexOfNextPhase != m_IndexOfCurrentPhase)
        {
            pCurrentPhase->OnLeave();

            if (m_IndexOfCurrentPhase == Phase::SHUTDOWN)
            {
                return false;
            }

            m_IndexOfCurrentPhase = indexOfNextPhase;

            pCurrentPhase = m_pPhases[m_IndexOfCurrentPhase];

            assert(pCurrentPhase != nullptr);

            pCurrentPhase->OnEnter();
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