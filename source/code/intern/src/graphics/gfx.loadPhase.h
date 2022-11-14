#pragma once

namespace Gfx
{
    class LoadPhase
    {
    public:
        static LoadPhase& GetInstance()
        {
            static LoadPhase instance;
            return instance;
        };

        LoadPhase(const LoadPhase&) = delete;
        LoadPhase& operator = (const LoadPhase&) = delete;

    public:
        void OnEnter();
        void OnRun();
        void OnLeave();

    private:
        LoadPhase()
        {};
    };
}