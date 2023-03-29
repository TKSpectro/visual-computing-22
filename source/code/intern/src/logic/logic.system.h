#pragma once
#include "../core/core_vector.h"

namespace Logic
{
    class System
    {
    public:
        static System& GetInstance()
        {
            static System instance;
            return instance;
        };

        System(const System&) = delete;
        System& operator = (const System&) = delete;

    public:

        void OnTurn();

    private:
        void HandleCommands();
        void MovePlayer(Core::Float2 orientation);
        void DetectCollision();

    private:
        System()
        {};
    };
}