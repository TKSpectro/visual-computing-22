#pragma once

namespace Data
{
    enum EventType
    {
        FINISH_MAP,
        DISPATCH_EVENT_TO_INPUT,
        DISPATCH_INPUT_TO_COMMAND,

        PRESSED_ESCAPE,
        PRESSED_ENTER,

        NumberOfMembers,
        Undefined = -1,
    };
}
