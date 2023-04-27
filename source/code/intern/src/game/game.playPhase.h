#pragma once

#include "game.phase.h"

#include "../data/data.event.h"

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
        // Callbacks
        static void FinishMap(Data::Event& event);

    private:
        bool finishedMap;
    };
}