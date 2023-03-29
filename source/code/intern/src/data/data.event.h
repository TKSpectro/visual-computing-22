#pragma once

namespace Data
{
    class Event
    {
    public:
        using BTypeID = int;

    public:
        void SetType(BTypeID type);
        BTypeID GetType() const;

    protected:
        BTypeID typeId;
    };
}
