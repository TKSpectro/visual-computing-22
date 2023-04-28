#include "gui.startupPhase.h"

#include <data/data.eventType.h>
#include <data/data.eventSystem.h>

#include <gui/gui.inputSystem.h>

namespace Gui
{
    void StartupPhase::OnEnter()
    {
        Data::EventSystem::GetInstance().Register(Data::EventType::DISPATCH_EVENT_TO_INPUT, &InputSystem::GetInstance().DispatchEventToInput);
    }

    void StartupPhase::OnRun()
    {}

    void StartupPhase::OnLeave()
    {}
}
