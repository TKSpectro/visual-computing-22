#include "data.pointSystem.h"

namespace Data
{
    int PointSystem::GetPoints()
    {
        return this->points;
    }

    int PointSystem::AddPoints(int _points)
    {
        this->points += _points;
        return this->points;
    }

    int PointSystem::ResetPoints()
    {
        this->points = 0;
        return this->points;
    }
}
