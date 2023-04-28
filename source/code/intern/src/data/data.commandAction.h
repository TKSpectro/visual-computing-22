#pragma once

namespace Data
{
    struct CommandType
    {
        enum CommandAction
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