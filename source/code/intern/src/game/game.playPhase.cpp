#include "game.playPhase.h"

#include <iostream>
#include <fstream>

#include "core/core_time.h"
#include "game/game.application.h"

#include "graphics/gfx.playPhase.h"
#include "gui/gui.playPhase.h"
#include "logic/logic.playPhase.h"

#include "data/data.entitySystem.h"
#include "data/data.playerSystem.h"
#include "data/data.pointSystem.h"

namespace Game
{
    int PlayPhase::InternOnEnter()
    {
        std::cout << "GAME::PLAY::Enter" << std::endl;

        Core::Time::Reset();
        finishedMap = false;

        Data::PointSystem::GetInstance().ResetPoints();

        Logic::PlayPhase::GetInstance().OnEnter();
        Gui::PlayPhase::GetInstance().OnEnter();
        Gfx::PlayPhase::GetInstance().OnEnter();

        return 0;
    }

    int PlayPhase::InternOnRun()
    {
        Core::Time::OnFrame();

        Logic::PlayPhase::GetInstance().OnRun();
        Gui::PlayPhase::GetInstance().OnRun();
        Gfx::PlayPhase::GetInstance().OnRun();

        if (finishedMap)
        {
            return Type::UNLOAD_MAP;
        }

        return Type::PLAY;
    }

    int PlayPhase::InternOnLeave()
    {
        std::cout << "GAME::PLAY::Leave" << std::endl;

        // Read old highscore
        std::ifstream inHighscoreFile;
        int points = 0;
        double time = 0.0;
        inHighscoreFile.open("highscore.txt");
        std::string line;
        std::getline(inHighscoreFile, line);
        if (!line.empty())
        {
            points = std::stoi(line);
            std::getline(inHighscoreFile, line);
            if (!line.empty())
            {
                time = std::stod(line);
            }
        }
        inHighscoreFile.close();

        // Only write new highscore if the current score is higher than the old one and if the score is the same then check the time
        if (Data::PointSystem::GetInstance().GetPoints() > points || (Data::PointSystem::GetInstance().GetPoints() == points && Core::Time::GetTime() < time))
        {
            // Write file with first line points and second line time
            std::ofstream outHighscoreFile;
            outHighscoreFile.open("highscore.txt");
            outHighscoreFile << Data::PointSystem::GetInstance().GetPoints() << std::endl;
            outHighscoreFile << Core::Time::GetTime() << std::endl;
            outHighscoreFile.close();
        }

        Logic::PlayPhase::GetInstance().OnLeave();
        Gui::PlayPhase::GetInstance().OnLeave();
        Gfx::PlayPhase::GetInstance().OnLeave();

        return 0;
    }
}
