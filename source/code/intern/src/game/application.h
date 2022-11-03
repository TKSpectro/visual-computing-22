#pragma once
#include <iostream>

#include "phase.h"

namespace Game {
    class Application {
        public:
        static Application& GetInstance();

        private:
        Application(const Application&) = delete;
        Application& operator = (const Application&) = delete;

        private:
        int m_IndexOfCurrentPhase;
        Phase* m_pPhases[Phase::NumberOfTypes];
        //std::array<Phase, Phase::NumberOfTypes> m_pPhases;

        private:
        Application();

        public:
        void Initialize();
        void Run();

        private:
        bool RunPhase();

    };
}