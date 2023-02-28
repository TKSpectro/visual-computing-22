#include "game.loadPhase.h"

#include <iostream>

#include "logic/logic.loadPhase.h"
#include "graphics/gfx.loadPhase.h"
#include "gui/gui.loadPhase.h"

namespace Game
{
    int LoadPhase::InternOnEnter()
    {
        std::cout << "GAME::LOAD::Enter" << std::endl;

        Gui::LoadPhase::GetInstance().OnEnter();
        Logic::LoadPhase::GetInstance().OnEnter();
        Gfx::LoadPhase::GetInstance().OnEnter();

        return 0;
    }

    int LoadPhase::InternOnRun()
    {
        std::cout << "GAME::LOAD::Run" << std::endl;

        Gui::LoadPhase::GetInstance().OnRun();
        Logic::LoadPhase::GetInstance().OnRun();
        Gfx::LoadPhase::GetInstance().OnRun();

        counter++;
        if (counter > 4)
        {
            counter = 0;
            return Type::PLAY;
        }

        return Type::LOAD_MAP;
    }

    int LoadPhase::InternOnLeave()
    {
        std::cout << "GAME::LOAD::Leave" << std::endl;

        Gui::LoadPhase::GetInstance().OnLeave();
        Logic::LoadPhase::GetInstance().OnLeave();
        Gfx::LoadPhase::GetInstance().OnLeave();

        return 0;
    }
}
