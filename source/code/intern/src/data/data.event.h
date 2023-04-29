#pragma once

#include "data.eventType.h"

namespace Data
{
    class Event
    {
    public:
        void SetType(EventType::Enum type);
        EventType::Enum GetType() const;

        void SetData(int data);
        int GetData() const;

    protected:
        EventType::Enum typeId;
        int data;
    };
}
