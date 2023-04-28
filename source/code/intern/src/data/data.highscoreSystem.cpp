#include "data.highscoreSystem.h"

#include <fstream>
#include <string>

#include "../core/core_time.h"

#include "data.pointSystem.h"

namespace Data
{
    int HighscoreSystem::GetPoints()
    {
        return this->points;
    }

    double HighscoreSystem::GetTime()
    {
        return this->time;
    }

    bool HighscoreSystem::GetLastRunNewHighscore()
    {
        return this->lastRunNewHighscore;
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
            this->points = std::stoi(line);
            std::getline(inHighscoreFile, line);
            if (!line.empty())
            {
                this->time = std::stod(line);

                // Could parse the file successfully
                isSuccess = true;
            }
        }

        inHighscoreFile.close();

        if (!isSuccess)
        {
            this->points = 0;
            this->time = 0.0;
        }

        return isSuccess;
    }

    bool HighscoreSystem::TryWriteHighscore()
    {
        this->TryReadHighscore();

        // Only write new highscore if the current score is higher than the old one and if the score is the same then check the time
        if (Data::PointSystem::GetInstance().GetPoints() > this->points || (Data::PointSystem::GetInstance().GetPoints() == this->points && Core::Time::GetTime() < this->time))
        {
            // Write file with first line points and second line time
            std::ofstream outHighscoreFile;
            outHighscoreFile.open(HIGHSCORE_FILE_NAME);
            outHighscoreFile << Data::PointSystem::GetInstance().GetPoints() << std::endl;
            outHighscoreFile << Core::Time::GetTime() << std::endl;
            outHighscoreFile.close();

            this->lastRunNewHighscore = true;
        } else
        {
            this->lastRunNewHighscore = false;
        }

        return this->lastRunNewHighscore;
    }
}
