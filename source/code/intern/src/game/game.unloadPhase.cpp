#include "game.unloadPhase.h"

#include <iostream>

#include "../logic/logic.unloadPhase.h"
#include "../graphics/gfx.unloadPhase.h"
#include "../gui/gui.unloadPhase.h"

namespace Game
{
    int UnloadPhase::InternOnEnter()
    {
        std::cout << "GAME::UNLOAD::Enter" << std::endl;

        Logic::UnloadPhase::GetInstance().OnEnter();
        Gfx::UnloadPhase::GetInstance().OnEnter();
        Gui::UnloadPhase::GetInstance().OnEnter();

        return 0;
    }

    int UnloadPhase::InternOnRun()
    {
        std::cout << "GAME::UNLOAD::Run" << std::endl;

        Logic::UnloadPhase::GetInstance().OnRun();
        Gfx::UnloadPhase::GetInstance().OnRun();
        Gui::UnloadPhase::GetInstance().OnRun();

        counter++;
        if (counter > 4)
        {
            return Type::SHUTDOWN;
        }

        return Type::UNLOAD_MAP;
    }

    int UnloadPhase::InternOnLeave()
    {
        std::cout << "GAME::UNLOAD::Leave" << std::endl;

        Logic::UnloadPhase::GetInstance().OnLeave();
        Gfx::UnloadPhase::GetInstance().OnLeave();
        Gui::UnloadPhase::GetInstance().OnLeave();

        return 0;
    }
}
