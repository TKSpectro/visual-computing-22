#pragma once

namespace Data
{
    struct EventType
    {
        enum Enum
        {
            FINISH_MAP,
            DISPATCH_EVENT_TO_INPUT,
            DISPATCH_INPUT_TO_COMMAND,

            PRESSED_ESCAPE,
            PRESSED_ENTER,
            PRESSED_NUMBER,

            NumberOfMembers,
            Undefined = -1,
        };
    };
}
