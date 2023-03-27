#include "data.playerSystem.h"

namespace Data
{
    Entity* PlayerSystem::GetPlayer()
    {
        return player;
    }

    void PlayerSystem::SetPlayer(Entity* _player)
    {
        player = _player;
    }

}
