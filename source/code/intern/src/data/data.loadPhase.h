#pragma once

#include <tinyxml2.h>

namespace Data
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
        void OnRun(tinyxml2::XMLDocument& doc);
        void OnLeave();

    private:
        LoadPhase()
        {};
    };
}