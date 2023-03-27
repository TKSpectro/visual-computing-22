#include "game.playPhase.h"

#include <iostream>

#include "core/core_time.h"
#include "game/game.application.h"

#include "graphics/gfx.playPhase.h"
#include "gui/gui.playPhase.h"

#include "data/data.entitySystem.h"
#include "data/data.playerSystem.h"

namespace Game
{
    int PlayPhase::InternOnEnter()
    {
        std::cout << "GAME::PLAY::Enter" << std::endl;

        Core::Time::Reset();

        Gui::PlayPhase::GetInstance().OnEnter();
        Gfx::PlayPhase::GetInstance().OnEnter();


        return 0;
    }

    int PlayPhase::InternOnRun()
    {
        Core::Time::OnFrame();
        // Now we can call getTime(), getFrameDuration()

        Gui::PlayPhase::GetInstance().OnRun();
        bool playerHitFinish = Gfx::PlayPhase::GetInstance().OnRun();

        if (playerHitFinish)
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
