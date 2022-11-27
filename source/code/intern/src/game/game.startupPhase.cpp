#include <iostream>
#include <tinyxml2.h>

#include "game.startupPhase.h"
#include "../data/data.startupPhase.h"

using namespace tinyxml2;

namespace Game
{
    int StartupPhase::InternOnEnter()
    {
        std::cout << "GAME::STARTUP::Enter" << std::endl;
        return 0;
    }

    int StartupPhase::InternOnRun()
    {
        std::cout << "GAME::STARTUP::Run" << std::endl;

        XMLDocument doc;
        doc.LoadFile("../code/intern/src/data/data.meta-entity.xml");

        Data::StartupPhase::GetInstance().OnRun(doc);

        // Normally we will load a resource-, file-, buffer-, model-managers here

        return Type::MAIN_MENU;
    }

    int StartupPhase::InternOnLeave()
    {
        std::cout << "GAME::STARTUP::Leave" << std::endl;
        return 0;
    }
}
