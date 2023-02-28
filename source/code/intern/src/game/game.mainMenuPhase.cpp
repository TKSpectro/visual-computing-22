#include "game.mainMenuPhase.h"

#include <iostream>

#include "data/data.mainMenuPhase.h"
#include "graphics/gfx.mainMenuPhase.h"
#include "gui/gui.mainMenuPhase.h"

namespace Game
{
    int MainMenuPhase::InternOnEnter()
    {
        std::cout << "GAME::MAINMENU::Enter" << std::endl;

        Data::MainMenuPhase::GetInstance().OnEnter();
        Gui::MainMenuPhase::GetInstance().OnEnter();
        Gfx::MainMenuPhase::GetInstance().OnEnter();

        return 0;
    }

    int MainMenuPhase::InternOnRun()
    {
        std::cout << "GAME::MAINMENU::Run" << std::endl;

        Data::MainMenuPhase::GetInstance().OnRun();
        Gui::MainMenuPhase::GetInstance().OnRun();
        Gfx::MainMenuPhase::GetInstance().OnRun();

        counter++;
        if (counter > 4)
        {
            counter = 0;
            return Type::LOAD_MAP;
        }

        return Type::MAIN_MENU;
    }

    int MainMenuPhase::InternOnLeave()
    {
        std::cout << "GAME::MAINMENU::Leave" << std::endl;

        Data::MainMenuPhase::GetInstance().OnLeave();
        Gui::MainMenuPhase::GetInstance().OnLeave();
        Gfx::MainMenuPhase::GetInstance().OnLeave();

        return 0;
    }
}
