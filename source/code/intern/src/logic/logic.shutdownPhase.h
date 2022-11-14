#pragma once

namespace Logic
{
    class ShutdownPhase
    {
    public:
        static ShutdownPhase& GetInstance()
        {
            static ShutdownPhase instance;
            return instance;
        };

        ShutdownPhase(const ShutdownPhase&) = delete;
        ShutdownPhase& operator = (const ShutdownPhase&) = delete;

    public:
        void OnEnter();
        void OnRun();
        void OnLeave();

    private:
        ShutdownPhase()
        {};
    };
}