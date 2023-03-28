#pragma once

#include <tinyxml2.h>

namespace Gfx
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
        void OnRun(tinyxml2::XMLDocument& doc);
        void OnLeave();

    private:
        StartupPhase()
        {};
    };
}