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
            NumberOfMembers,
            Undefined = -1,
        };
    };
}
