#include "game.startupPhase.h"

#include <iostream>
#include <tinyxml2.h>

#include "../data/data.startupPhase.h"
#include "../logic/logic.startupPhase.h"
#include "../graphics/gfx.startupPhase.h"
#include "../gui/gui.startupPhase.h"

using namespace tinyxml2;

namespace Game
{
    int StartupPhase::InternOnEnter()
    {
        std::cout << "GAME::STARTUP::Enter" << std::endl;

        Data::StartupPhase::GetInstance().OnEnter();
        Logic::StartupPhase::GetInstance().OnEnter();
        Gfx::StartupPhase::GetInstance().OnEnter();
        Gui::StartupPhase::GetInstance().OnEnter();

        return 0;
    }

    int StartupPhase::InternOnRun()
    {
        std::cout << "GAME::STARTUP::Run" << std::endl;

        XMLDocument doc;
        doc.LoadFile("../code/intern/src/data/data.meta-entity.xml");

        Data::StartupPhase::GetInstance().OnRun(doc);
        Logic::StartupPhase::GetInstance().OnRun();
        Gfx::StartupPhase::GetInstance().OnRun();
        Gui::StartupPhase::GetInstance().OnRun();

        // Normally we will load a resource-, file-, buffer-, model-managers here

        return Type::MAIN_MENU;
    }

    int StartupPhase::InternOnLeave()
    {
        std::cout << "GAME::STARTUP::Leave" << std::endl;

        Data::StartupPhase::GetInstance().OnLeave();
        Logic::StartupPhase::GetInstance().OnLeave();
        Gfx::StartupPhase::GetInstance().OnLeave();
        Gui::StartupPhase::GetInstance().OnLeave();

        return 0;
    }
}
