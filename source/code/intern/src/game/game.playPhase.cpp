#include "game.playPhase.h"

#include <iostream>
#include <fstream>

#include "core/core_time.h"

#include "game/game.application.h"

#include "data/data.entitySystem.h"
#include "data/data.playerSystem.h"
#include "data/data.pointSystem.h"
#include "data/data.highscoreSystem.h"
#include "data/data.eventSystem.h"

#include "graphics/gfx.playPhase.h"
#include "gui/gui.playPhase.h"
#include "logic/logic.playPhase.h"

namespace Game
{
    int PlayPhase::InternOnEnter()
    {
        std::cout << "GAME::PLAY::Enter" << std::endl;

        nextRunPhase = Type::PLAY;

        Core::Time::Reset();

        Data::EventSystem::GetInstance().Register(Data::EventType::FINISH_MAP, &FinishMap);
        Data::EventSystem::GetInstance().Register(Data::EventType::PRESSED_ESCAPE, &Exit);

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

        return nextRunPhase;
    }

    int PlayPhase::InternOnLeave()
    {
        std::cout << "GAME::PLAY::Leave" << std::endl;

        Data::EventSystem::GetInstance().Unregister(Data::EventType::FINISH_MAP, &FinishMap);
        Data::EventSystem::GetInstance().Unregister(Data::EventType::PRESSED_ESCAPE, &Exit);

        Logic::PlayPhase::GetInstance().OnLeave();
        Gui::PlayPhase::GetInstance().OnLeave();
        Gfx::PlayPhase::GetInstance().OnLeave();

        return 0;
    }

    void PlayPhase::FinishMap(Data::Event& /* event */)
    {
        Data::HighscoreSystem::GetInstance().TryWriteHighscore();

        PlayPhase::GetInstance().nextRunPhase = Type::MAIN_MENU;
    }

    void PlayPhase::Exit(Data::Event& /* event */)
    {
        PlayPhase::GetInstance().nextRunPhase = Type::MAIN_MENU;
    }
}
