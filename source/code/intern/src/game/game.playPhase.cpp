#include "game.playPhase.h"

#include <iostream>

#include "game/game.application.h"

#include "graphics/gfx.playPhase.h"
#include "gui/gui.playPhase.h"

namespace Game
{
    int PlayPhase::InternOnEnter()
    {
        std::cout << "GAME::PLAY::Enter" << std::endl;

        Gfx::PlayPhase::GetInstance().OnEnter();
        Gui::PlayPhase::GetInstance().OnEnter();

        return 0;
    }

    int PlayPhase::InternOnRun()
    {
        if (counter % 100 == 0)
        {
            std::cout << "GAME::PLAY::Run::" << counter << std::endl;
        }

        Gfx::PlayPhase::GetInstance().OnRun();
        Gui::PlayPhase::GetInstance().OnRun();

        counter++;
        if (counter > 2000)
        {
            return Type::UNLOAD_MAP;
        }

        return Type::PLAY;
    }

    int PlayPhase::InternOnLeave()
    {
        std::cout << "GAME::PLAY::Leave" << std::endl;

        Gfx::PlayPhase::GetInstance().OnLeave();
        Gui::PlayPhase::GetInstance().OnLeave();

        return 0;
    }
}
