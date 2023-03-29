#pragma once

namespace Logic
{
    class PlayPhase
    {
    public:
        static PlayPhase& GetInstance()
        {
            static PlayPhase instance;
            return instance;
        };

        PlayPhase(const PlayPhase&) = delete;
        PlayPhase& operator = (const PlayPhase&) = delete;

    public:
        void OnEnter();
        void OnRun();
        void OnLeave();

    private:
        PlayPhase()
        {};

    private:
        static const unsigned int TURNS_PER_SECOND = 10;
        const double TURN_INTERVAL = 1.0 / TURNS_PER_SECOND;
        double nextTurnTime;
    };
}