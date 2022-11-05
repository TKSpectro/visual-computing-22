#pragma once
#include "phase.h"

namespace Game
{
    class UnloadPhase : public Phase
    {
    public:
        static UnloadPhase& GetInstance()
        {
            static UnloadPhase instance;
            return instance;
        };

        UnloadPhase(const UnloadPhase&) = delete;
        UnloadPhase& operator = (const UnloadPhase&) = delete;

    private:
        UnloadPhase()
        {};

        int counter = 0;

    private:
        int InternOnEnter() override;
        int InternOnRun() override;
        int InternOnLeave() override;
    };
}