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

        // TODO: Reset timer

        Gui::PlayPhase::GetInstance().OnEnter();
        Gfx::PlayPhase::GetInstance().OnEnter();


        return 0;
    }

    int PlayPhase::InternOnRun()
    {
        // TODO: Call timer::OnFrame;
        // Can call getTime(), getFrameDuration

        if (counter % 100 == 0)
        {
            std::cout << "GAME::PLAY::Run::" << counter << std::endl;
        }

        Gui::PlayPhase::GetInstance().OnRun();
        Gfx::PlayPhase::GetInstance().OnRun();


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

        Gui::PlayPhase::GetInstance().OnLeave();
        Gfx::PlayPhase::GetInstance().OnLeave();

        return 0;
    }
}
