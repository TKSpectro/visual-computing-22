#pragma once

namespace Data
{
    struct EntityCategory
    {
        enum Enum
        {
            Character,
            Ground,
            Obstacle,
            Finish,
            Coin,
            NumberOfMembers,
            Undefined = -1,
        };
    };
}
