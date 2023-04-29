#include "game.mainMenuPhase.h"

#include <iostream>

#include "data/data.mainMenuPhase.h"
#include "data/data.mapPickerSystem.h"
#include "data/data.eventSystem.h"
#include "gui/gui.mainMenuPhase.h"
#include "graphics/gfx.mainMenuPhase.h"

namespace Game
{
    int MainMenuPhase::InternOnEnter()
    {
        std::cout << "GAME::MAINMENU::Enter" << std::endl;

        nextRunPhase = Phase::MAIN_MENU;

        Data::EventSystem::GetInstance().Register(Data::EventType::PRESSED_ENTER, &MainMenuPhase::OnStart);
        Data::EventSystem::GetInstance().Register(Data::EventType::PRESSED_ESCAPE, &MainMenuPhase::OnExit);
        Data::EventSystem::GetInstance().Register(Data::EventType::PRESSED_NUMBER, &MainMenuPhase::OnNumber);

        Data::MainMenuPhase::GetInstance().OnEnter();
        Gui::MainMenuPhase::GetInstance().OnEnter();
        Gfx::MainMenuPhase::GetInstance().OnEnter();

        return 0;
    }

    int MainMenuPhase::InternOnRun()
    {
        Data::MainMenuPhase::GetInstance().OnRun();
        Gui::MainMenuPhase::GetInstance().OnRun();
        Gfx::MainMenuPhase::GetInstance().OnRun();

        return nextRunPhase;
    }

    int MainMenuPhase::InternOnLeave()
    {
        std::cout << "GAME::MAINMENU::Leave" << std::endl;

        Data::EventSystem::GetInstance().Unregister(Data::EventType::PRESSED_ENTER, &MainMenuPhase::OnStart);
        Data::EventSystem::GetInstance().Unregister(Data::EventType::PRESSED_ESCAPE, &MainMenuPhase::OnExit);
        Data::EventSystem::GetInstance().Unregister(Data::EventType::PRESSED_NUMBER, &MainMenuPhase::OnNumber);

        Data::MainMenuPhase::GetInstance().OnLeave();
        Gui::MainMenuPhase::GetInstance().OnLeave();
        Gfx::MainMenuPhase::GetInstance().OnLeave();

        return 0;
    }

    void MainMenuPhase::OnStart(Data::Event& /* event */)
    {
        MainMenuPhase::GetInstance().nextRunPhase = Phase::LOAD_MAP;
    }

    void MainMenuPhase::OnExit(Data::Event& /* event */)
    {
        MainMenuPhase::GetInstance().nextRunPhase = Phase::SHUTDOWN;
    }

    void MainMenuPhase::OnNumber(Data::Event& event)
    {
        Data::MapPickerSystem::GetInstance().SetMapIndex(event.GetData() - 1);
    }
}
