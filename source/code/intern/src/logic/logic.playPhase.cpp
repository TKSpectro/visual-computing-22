#include "logic.playPhase.h"

#include <iostream>

#include "../core/core_time.h"
#include "../data/data.eventSystem.h"

#include "logic.system.h"
#include "logic.commandSystem.h"

namespace Logic
{
    void PlayPhase::OnEnter()
    {
        Data::EventSystem::GetInstance().Register(Data::EventType::DISPATCH_INPUT_TO_COMMAND, &CommandSystem::DispatchInputToLogic);
        // Reset the turn timer
        nextTurnTime = Core::Time::GetTime() + TURN_INTERVAL;
    }

    void PlayPhase::OnRun()
    {
        if (Core::Time::GetTime() >= nextTurnTime)
        {
            nextTurnTime += TURN_INTERVAL;

            System::GetInstance().OnTurn();
        }
    }

    void PlayPhase::OnLeave()
    {
        Data::EventSystem::GetInstance().Unregister(Data::EventType::DISPATCH_INPUT_TO_COMMAND, &CommandSystem::DispatchInputToLogic);

        nextTurnTime = 0.0;
    }
}
