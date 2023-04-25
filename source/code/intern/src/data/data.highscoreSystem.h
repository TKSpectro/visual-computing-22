#pragma once

#include <string>

namespace Data
{
    class HighscoreSystem
    {
    public:
        static HighscoreSystem& GetInstance()
        {
            static HighscoreSystem instance;
            return instance;
        };

        const std::string HIGHSCORE_FILE_NAME = "highscore.txt";

        HighscoreSystem(const HighscoreSystem&) = delete;
        HighscoreSystem& operator = (const HighscoreSystem&) = delete;

    public:
        int GetPoints();
        double GetTime();

        bool GetLastRunNewHighscore();

        bool TryReadHighscore();
        bool TryWriteHighscore();

    private:
        HighscoreSystem()
        {};

    private:
        int points;
        double time;
        bool lastRunNewHighscore;
    };
}