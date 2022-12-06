#pragma once

#include "data.entityCategory.h"
#include "data.entityFolder.h"

namespace Data
{
    class Sector
    {
    private:

        int           positionX;
        int           positionY;
        EntityFolder folders[EntityCategory::NumberOfMembers];
    };
}
