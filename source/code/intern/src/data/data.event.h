#pragma once

#include "data.eventType.h"

namespace Data
{
    class Event
    {
    public:
        void SetType(EventType type);
        EventType GetType() const;

        void SetData(int data);
        int GetData() const;

    protected:
        EventType typeId;
        int data;
    };
}
