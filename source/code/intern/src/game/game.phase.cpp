#include "game.phase.h"

namespace Game
{
    int Phase::OnEnter()
    {
        return InternOnEnter();
    }

    int Phase::OnRun()
    {
        return InternOnRun();
    }

    int Phase::OnLeave()
    {
        return InternOnLeave();
    }
}
