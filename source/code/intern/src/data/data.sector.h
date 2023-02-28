#pragma once

#include "data.entityCategory.h"
#include "data.entityFolder.h"

namespace Data
{
    class Sector
    {
    public:

        int           positionX;
        int           positionY;
        EntityFolder folders[EntityCategory::NumberOfMembers];
    };
}
