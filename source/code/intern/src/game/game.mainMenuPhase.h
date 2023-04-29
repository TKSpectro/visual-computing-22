#pragma once
#include "game.phase.h"

#include <data/data.event.h>

namespace Game
{
    class MainMenuPhase : public Phase
    {
    public:
        static MainMenuPhase& GetInstance()
        {
            static MainMenuPhase instance;
            return instance;
        };

        MainMenuPhase(MainMenuPhase const&) = delete;
        MainMenuPhase& operator=(MainMenuPhase const&) = delete;

    private:
        MainMenuPhase() :
            nextRunPhase(Phase::MAIN_MENU)
        {};

    private:
        Phase::Type nextRunPhase;

    private:
        int InternOnEnter() override;
        int InternOnRun() override;
        int InternOnLeave() override;

    public:
        // Callbacks
        static void OnStart(Data::Event& event);
        static void OnExit(Data::Event& event);
        static void OnNumber(Data::Event& event);
    };
}