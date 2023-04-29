#include "game.startupPhase.h"

#include <iostream>
#include <tinyxml2.h>

#include "data/data.startupPhase.h"
#include "gui/gui.startupPhase.h"
#include "logic/logic.startupPhase.h"
#include "graphics/gfx.startupPhase.h"

using namespace tinyxml2;

namespace Game
{
    int StartupPhase::InternOnEnter()
    {
        std::cout << "GAME::STARTUP::Enter" << std::endl;

        Data::StartupPhase::GetInstance().OnEnter();
        Gui::StartupPhase::GetInstance().OnEnter();
        Logic::StartupPhase::GetInstance().OnEnter();
        Gfx::StartupPhase::GetInstance().OnEnter();

        return 0;
    }

    int StartupPhase::InternOnRun()
    {
        std::cout << "GAME::STARTUP::Run" << std::endl;

        XMLDocument* doc = new XMLDocument();
        doc->LoadFile("meta/data.meta-entity.xml");

        Data::StartupPhase::GetInstance().OnRun(*doc);
        Gui::StartupPhase::GetInstance().OnRun();
        Logic::StartupPhase::GetInstance().OnRun();
        Gfx::StartupPhase::GetInstance().OnRun(*doc);

        // Normally we will load a resource-, file-, buffer-, model-managers here

        return Type::MAIN_MENU;
    }

    int StartupPhase::InternOnLeave()
    {
        std::cout << "GAME::STARTUP::Leave" << std::endl;

        Data::StartupPhase::GetInstance().OnLeave();
        Gui::StartupPhase::GetInstance().OnLeave();
        Logic::StartupPhase::GetInstance().OnLeave();
        Gfx::StartupPhase::GetInstance().OnLeave();

        return 0;
    }
}
