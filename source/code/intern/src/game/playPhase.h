#pragma once
#include "phase.h"

namespace Game
{
    class PlayPhase : public Phase
    {
    public:
        static PlayPhase& GetInstance()
        {
            static PlayPhase instance;
            return instance;
        };

        PlayPhase(const PlayPhase&) = delete;
        PlayPhase& operator = (const PlayPhase&) = delete;
    private:
        PlayPhase()
        {};

        int counter = 0;

    private:
        int InternOnEnter() override;
        int InternOnRun() override;
        int InternOnLeave() override;
    };
}