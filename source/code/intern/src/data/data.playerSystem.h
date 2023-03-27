#pragma once

#include "data.entity.h"

namespace Data
{
    class PlayerSystem
    {
    public:
        static PlayerSystem& GetInstance()
        {
            static PlayerSystem instance;
            return instance;
        };

        PlayerSystem(const PlayerSystem&) = delete;
        PlayerSystem& operator = (const PlayerSystem&) = delete;

    public:
        Entity* GetPlayer();
        void SetPlayer(Entity* player);

    private:
        PlayerSystem()
        {};

    private:
        Entity* player;
    };
}