#pragma once

namespace Data
{
    struct CommandAction
    {
        enum Enum
        {
            MoveUp,
            MoveDown,
            MoveLeft,
            MoveRight,
            NumberOfTypes,
            Undefined = -1,
        };
    };
}