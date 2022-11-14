#pragma once
#include "game.phase.h"

namespace Game
{
    class LoadPhase : public Phase
    {
    public:
        static LoadPhase& GetInstance()
        {
            static LoadPhase instance;
            return instance;
        };

        LoadPhase(const LoadPhase&) = delete;
        LoadPhase& operator = (const LoadPhase&) = delete;

    private:
        LoadPhase()
        {};

        int counter = 0;

    private:
        int InternOnEnter() override;
        int InternOnRun() override;
        int InternOnLeave() override;
    };
}