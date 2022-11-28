#include "game.shutdownPhase.h"

#include <iostream>

#include "game.application.h"

#include "../data/data.shutdownPhase.h"
#include "../logic/logic.shutdownPhase.h"
#include "../graphics/gfx.shutdownPhase.h"
#include "../gui/gui.shutdownPhase.h"

namespace Game
{
    int ShutdownPhase::InternOnEnter()
    {
        std::cout << "GAME::SHUTDOWN::Enter" << std::endl;

        Data::ShutdownPhase::GetInstance().OnEnter();
        Logic::ShutdownPhase::GetInstance().OnEnter();
        Gfx::ShutdownPhase::GetInstance().OnEnter();
        Gui::ShutdownPhase::GetInstance().OnEnter();

        return 0;
    }

    int ShutdownPhase::InternOnRun()
    {
        std::cout << "GAME::SHUTDOWN::Run" << std::endl;

        Data::ShutdownPhase::GetInstance().OnRun();
        Logic::ShutdownPhase::GetInstance().OnRun();
        Gfx::ShutdownPhase::GetInstance().OnRun();
        Gui::ShutdownPhase::GetInstance().OnRun();

        counter++;
        if (counter > 4)
        {
            return Type::Undefined;
        }

        return Type::SHUTDOWN;
    }

    int ShutdownPhase::InternOnLeave()
    {
        std::cout << "GAME::SHUTDOWN::Leave" << std::endl;

        Data::ShutdownPhase::GetInstance().OnLeave();
        Logic::ShutdownPhase::GetInstance().OnLeave();
        Gfx::ShutdownPhase::GetInstance().OnLeave();
        Gui::ShutdownPhase::GetInstance().OnLeave();

        Application::GetInstance().window.close();

        return 0;
    }
}
