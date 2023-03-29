#pragma once
#include "game.phase.h"

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
            : finishedMap(false)
        {};

    private:
        int InternOnEnter() override;
        int InternOnRun() override;
        int InternOnLeave() override;

    public:
        bool finishedMap;
    };
}