#include "data.event.h"

namespace Data
{
    void Event::SetType(EventType::Enum _type)
    {
        typeId = _type;
    }

    EventType::Enum Event::GetType() const
    {
        return typeId;
    }

    void Event::SetData(int _data)
    {
        data = _data;
    }

    int Event::GetData() const
    {
        return data;
    }
}
