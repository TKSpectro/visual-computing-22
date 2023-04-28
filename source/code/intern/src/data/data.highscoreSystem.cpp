#include "data.highscoreSystem.h"

#include <fstream>
#include <string>

#include "../core/core_time.h"

#include "data.pointSystem.h"

namespace Data
{
    int HighscoreSystem::GetPoints()
    {
        return points;
    }

    double HighscoreSystem::GetTime()
    {
        return time;
    }

    bool HighscoreSystem::GetLastRunNewHighscore()
    {
        return lastRunNewHighscore;
    }

    bool HighscoreSystem::TryReadHighscore()
    {
        bool isSuccess = false;

        std::ifstream inHighscoreFile;
        inHighscoreFile.open(HIGHSCORE_FILE_NAME);
        std::string line;
        std::getline(inHighscoreFile, line);
        if (!line.empty())
        {
            points = std::stoi(line);
            std::getline(inHighscoreFile, line);
            if (!line.empty())
            {
                time = std::stod(line);

                // Could parse the file successfully
                isSuccess = true;
            }
        }

        inHighscoreFile.close();

        if (!isSuccess)
        {
            points = 0;
            time = 0.0;
        }

        return isSuccess;
    }

    bool HighscoreSystem::TryWriteHighscore()
    {
        TryReadHighscore();

        // Only write new highscore if the current score is higher than the old one and if the score is the same then check the time
        if (Data::PointSystem::GetInstance().GetPoints() > points || (Data::PointSystem::GetInstance().GetPoints() == points && Core::Time::GetTime() < time))
        {
            // Write file with first line points and second line time
            std::ofstream outHighscoreFile;
            outHighscoreFile.open(HIGHSCORE_FILE_NAME);
            outHighscoreFile << Data::PointSystem::GetInstance().GetPoints() << std::endl;
            outHighscoreFile << Core::Time::GetTime() << std::endl;
            outHighscoreFile.close();

            lastRunNewHighscore = true;
        } else
        {
            lastRunNewHighscore = false;
        }

        return lastRunNewHighscore;
    }
}
