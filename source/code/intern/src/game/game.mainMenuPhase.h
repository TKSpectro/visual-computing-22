#pragma once
#include "game.phase.h"

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
        MainMenuPhase()
        {};

        int counter = 0;

    private:
        int InternOnEnter() override;
        int InternOnRun() override;
        int InternOnLeave() override;
    };
}