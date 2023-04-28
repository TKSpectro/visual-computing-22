#include "gui.mainMenuPhase.h"

#include <SFML/Window/Keyboard.hpp>

#include "gui.inputSystem.h"

namespace Gui
{
    void MainMenuPhase::OnEnter()
    {}

    void MainMenuPhase::OnRun()
    {
        InputSystem::GetInstance().OnRun();
    }

    void MainMenuPhase::OnLeave()
    {}
}
