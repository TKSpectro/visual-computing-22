#include "phase.h"

int Game::Phase::OnEnter()
{
    return InternOnEnter();
}

int Game::Phase::OnRun()
{
    return InternOnRun();
}

int Game::Phase::OnLeave()
{
    return InternOnLeave();
}
