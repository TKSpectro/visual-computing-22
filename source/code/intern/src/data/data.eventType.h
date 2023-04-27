#pragma once
#include <list>

#include "data.event.h"
#include "data.eventListener.h"

namespace Data
{
    enum EventType
    {
        FINISH_MAP,
        TEST_CB1,
        TEST_CB2,

        NumberOfMembers,
        Undefined = -1,
    };
}
