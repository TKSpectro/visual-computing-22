#include "startupPhase.h"
#include <iostream>

namespace Game
{
    int StartupPhase::InternOnEnter()
    {
        std::cout << "STARTUP::Enter" << std::endl;
        return 0;
    }

    int StartupPhase::InternOnRun()
    {
        std::cout << "STARTUP::Run" << std::endl;

        counter++;

        if (counter > 4)
        {
            counter = 0;
            return Type::MAIN_MENU;
        }

        return Type::STARTUP;
    }

    int StartupPhase::InternOnLeave()
    {
        std::cout << "STARTUP::Leave" << std::endl;
        return 0;
    }
}
