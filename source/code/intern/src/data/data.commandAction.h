#pragma once

namespace Data
{
    struct CommandAction
    {
        enum CommandActionEnum
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