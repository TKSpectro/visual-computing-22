#include "data.pointSystem.h"

int Data::PointSystem::GetPoints()
{
    return this->points;
}

int Data::PointSystem::AddPoints(int _points)
{
    this->points += _points;
    return this->points;
}

int Data::PointSystem::ResetPoints()
{
    this->points = 0;
    return this->points;
}
