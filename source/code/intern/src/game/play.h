#pragma once
#include "phase.h"

namespace Game {
    class PlayPhase : Phase {
        public:
        static PlayPhase& GetInstance();

        private:
        PlayPhase();

        private:
        int InternOnEnter() override;
        int InternOnRun() override;
        int InternOnLeave() override;

        private:
        PlayPhase(const PlayPhase&) = delete;
        PlayPhase& operator = (const PlayPhase&) = delete;
    };
}