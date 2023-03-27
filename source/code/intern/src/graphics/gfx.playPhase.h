#pragma once

namespace Gfx
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
        bool OnRun();
        void OnLeave();

    private:
        PlayPhase()
        {};
    };
}