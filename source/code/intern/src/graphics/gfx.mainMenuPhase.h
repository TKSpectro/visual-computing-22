#pragma once

namespace Gfx
{
    class MainMenuPhase
    {
    public:
        static MainMenuPhase& GetInstance()
        {
            static MainMenuPhase instance;
            return instance;
        };

        MainMenuPhase(const MainMenuPhase&) = delete;
        MainMenuPhase& operator = (const MainMenuPhase&) = delete;

    public:
        void OnEnter();
        void OnRun();
        void OnLeave();

    private:
        MainMenuPhase()
        {};
    };
}