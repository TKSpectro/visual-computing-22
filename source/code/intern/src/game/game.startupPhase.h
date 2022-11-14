#pragma once
#include "game.phase.h"

namespace Game
{
    class StartupPhase : public Phase
    {
    public:
        static StartupPhase& GetInstance()
        {
            static StartupPhase instance;
            return instance;
        };

        StartupPhase(const StartupPhase&) = delete;
        StartupPhase& operator = (const StartupPhase&) = delete;

    private:
        StartupPhase()
        {};

        int counter = 0;

    private:
        int InternOnEnter() override;
        int InternOnRun() override;
        int InternOnLeave() override;
    };
}