#include "data.pointSystem.h"

namespace Data
{
    int PointSystem::GetPoints()
    {
        return points;
    }

    int PointSystem::AddPoints(int _points)
    {
        points += _points;
        return points;
    }

    int PointSystem::ResetPoints()
    {
        points = 0;
        return points;
    }
}
