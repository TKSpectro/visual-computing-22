#include "game.unloadPhase.h"

#include <iostream>

#include "data/data.unloadPhase.h"
#include "gui/gui.unloadPhase.h"
#include "logic/logic.unloadPhase.h"
#include "graphics/gfx.unloadPhase.h"

namespace Game
{
    int UnloadPhase::InternOnEnter()
    {
        std::cout << "GAME::UNLOAD::Enter" << std::endl;

        Data::UnloadPhase::GetInstance().OnEnter();
        Gui::UnloadPhase::GetInstance().OnEnter();
        Logic::UnloadPhase::GetInstance().OnEnter();
        Gfx::UnloadPhase::GetInstance().OnEnter();

        return 0;
    }

    int UnloadPhase::InternOnRun()
    {
        std::cout << "GAME::UNLOAD::Run" << std::endl;

        Data::UnloadPhase::GetInstance().OnRun();
        Gui::UnloadPhase::GetInstance().OnRun();
        Logic::UnloadPhase::GetInstance().OnRun();
        Gfx::UnloadPhase::GetInstance().OnRun();

        return Type::MAIN_MENU;
    }

    int UnloadPhase::InternOnLeave()
    {
        std::cout << "GAME::UNLOAD::Leave" << std::endl;

        Data::UnloadPhase::GetInstance().OnLeave();
        Gui::UnloadPhase::GetInstance().OnLeave();
        Logic::UnloadPhase::GetInstance().OnLeave();
        Gfx::UnloadPhase::GetInstance().OnLeave();

        return 0;
    }
}
