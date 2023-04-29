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
        PlayPhase() :
            nextRunPhase(Phase::PLAY)
        {};

    private:
        int InternOnEnter() override;
        int InternOnRun() override;
        int InternOnLeave() override;

    public:
        // Callbacks
        static void FinishMap(Data::Event& event);
        static void Exit(Data::Event& event);

    private:
        Phase::Type nextRunPhase;
    };
}