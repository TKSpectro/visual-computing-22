#include "gui.shutdownPhase.h"

#include "data/data.eventSystem.h"

#include "gui.inputSystem.h"

namespace Gui
{
    void ShutdownPhase::OnEnter()
    {}

    void ShutdownPhase::OnRun()
    {}

    void ShutdownPhase::OnLeave()
    {
        Data::EventSystem::GetInstance().Unregister(Data::EventType::DISPATCH_EVENT_TO_INPUT, &InputSystem::GetInstance().DispatchEventToInput);
    }
}
