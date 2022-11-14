#pragma once

namespace Gui
{
    class StartupPhase
    {
    public:
        static StartupPhase& GetInstance()
        {
            static StartupPhase instance;
            return instance;
        };

        StartupPhase(const StartupPhase&) = delete;
        StartupPhase& operator = (const StartupPhase&) = delete;

    public:
        void OnEnter();
        void OnRun();
        void OnLeave();

    private:
        StartupPhase()
        {};
    };
}