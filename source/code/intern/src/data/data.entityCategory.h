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
            NumberOfMembers,
            Undefined = -1,
        };
    };
}
