#include "logic.playPhase.h"

#include <iostream>

#include "../core/core_time.h"

#include "logic.system.h"

namespace Logic
{
    void PlayPhase::OnEnter()
    {}

    void PlayPhase::OnRun()
    {
        if (Core::Time::GetTime() >= nextTurnTime)
        {
            nextTurnTime += TURN_INTERVAL;

            System::GetInstance().OnTurn();
        }
    }

    void PlayPhase::OnLeave()
    {}
}
