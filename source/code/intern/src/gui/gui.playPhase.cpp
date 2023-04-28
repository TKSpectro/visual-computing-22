#include "gui.playPhase.h"

#include "gui.inputSystem.h"

namespace Gui
{
    void PlayPhase::OnEnter()
    {}

    void PlayPhase::OnRun()
    {
        InputSystem::GetInstance().OnRun();
    }

    void PlayPhase::OnLeave()
    {}
}
