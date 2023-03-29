#include "data.event.h"

namespace Data
{
    void Data::Event::SetType(BTypeID type)
    {
        this->typeId = type;
    }

    Data::Event::BTypeID Data::Event::GetType() const
    {
        return this->typeId;
    }
}
