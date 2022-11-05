#include <SFML/Graphics.hpp>
#include <cassert>

#include "application.h"
#include "phase.h"
#include "startupPhase.h"
#include "mainMenuPhase.h"
#include "loadPhase.h"
#include "playPhase.h"
#include "unloadPhase.h"
#include "shutdownPhase.h"

namespace Game {
    Application::Application()
        : m_IndexOfCurrentPhase(Phase::Undefined),
        m_pPhases{
        &StartupPhase::GetInstance(),
        &MainMenuPhase::GetInstance(),
        &LoadPhase::GetInstance(),
        &PlayPhase::GetInstance(),
        &UnloadPhase::GetInstance(),
        &ShutdownPhase::GetInstance()
    } {

    }

    void Application::Initialize() {
        // Enable fancy anitaliasing
        sf::ContextSettings settings;
        settings.antialiasingLevel = 8;

        m_window.create(sf::VideoMode(800, 450), "vc22 - Tom Kaeppler", sf::Style::Default, settings);

        m_IndexOfCurrentPhase = Phase::STARTUP;
        m_pPhases[m_IndexOfCurrentPhase]->OnEnter();
    }

    void Application::Run() {
        for (;;) {
            if (m_window.isOpen() == false) {
                break;
            }

            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (m_window.pollEvent(event)) {
                // "close requested" event: we close the m_window
                if (event.type == sf::Event::Closed)
                    m_window.close();
            }

            if (RunPhase() == false) {
                break;
            }
        }
    }

    bool Application::RunPhase() {
        Phase* pCurrentPhase = m_pPhases[m_IndexOfCurrentPhase];
        assert(pCurrentPhase != nullptr);

        int indexOfNextPhase = pCurrentPhase->OnRun();

        if (indexOfNextPhase != m_IndexOfCurrentPhase) {
            pCurrentPhase->OnLeave();

            if (m_IndexOfCurrentPhase == Phase::SHUTDOWN) {
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

int main() {
    Game::Application::GetInstance().Initialize();

    Game::Application::GetInstance().Run();

    return 0;
}