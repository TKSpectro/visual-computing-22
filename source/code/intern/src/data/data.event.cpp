#include "data.event.h"

namespace Data
{
    void Event::SetType(EventType type)
    {
        this->typeId = type;
    }

    EventType Event::GetType() const
    {
        return this->typeId;
    }

    void Event::SetData(int data)
    {
        this->data = data;
    }
    
    int Event::GetData() const
    {
        return this->data;
    }
}
