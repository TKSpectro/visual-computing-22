#pragma once

namespace Data
{
    class PointSystem
    {
    public:
        static PointSystem& GetInstance()
        {
            static PointSystem instance;
            return instance;
        };

        PointSystem(const PointSystem&) = delete;
        PointSystem& operator = (const PointSystem&) = delete;

    public:
        int GetPoints();
        int AddPoints(int points);
        int ResetPoints();

    private:
        PointSystem() :
            points(0)
        {};

    private:
        int points;
    };
}