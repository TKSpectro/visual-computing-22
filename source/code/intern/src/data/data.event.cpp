#include "data.event.h"

namespace Data
{
    void Data::Event::SetType(BTypeID type)
    {
        this->type = type;
    }

    Data::Event::BTypeID Data::Event::GetType() const
    {
        return this->type;
    }
}
