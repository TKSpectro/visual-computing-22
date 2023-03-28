#include "game.loadPhase.h"

#include <iostream>
#include <tinyxml2.h>

#include "data/data.loadPhase.h"
#include "logic/logic.loadPhase.h"
#include "graphics/gfx.loadPhase.h"
#include "gui/gui.loadPhase.h"

using namespace tinyxml2;

namespace Game
{
    int LoadPhase::InternOnEnter()
    {
        std::cout << "GAME::LOAD::Enter" << std::endl;

        Data::LoadPhase::GetInstance().OnEnter();
        Gui::LoadPhase::GetInstance().OnEnter();
        Logic::LoadPhase::GetInstance().OnEnter();
        Gfx::LoadPhase::GetInstance().OnEnter();

        return 0;
    }

    int LoadPhase::InternOnRun()
    {
        std::cout << "GAME::LOAD::Run" << std::endl;

        XMLDocument doc;
        doc.LoadFile("data.map-1.xml");

        Data::LoadPhase::GetInstance().OnRun(doc);
        Gui::LoadPhase::GetInstance().OnRun();
        Logic::LoadPhase::GetInstance().OnRun();
        Gfx::LoadPhase::GetInstance().OnRun();

        return Type::PLAY;
    }

    int LoadPhase::InternOnLeave()
    {
        std::cout << "GAME::LOAD::Leave" << std::endl;

        Data::LoadPhase::GetInstance().OnLeave();
        Gui::LoadPhase::GetInstance().OnLeave();
        Logic::LoadPhase::GetInstance().OnLeave();
        Gfx::LoadPhase::GetInstance().OnLeave();

        return 0;
    }
}
