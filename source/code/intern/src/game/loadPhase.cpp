#include "loadPhase.h"
#include <iostream>

namespace Game
{
    int LoadPhase::InternOnEnter()
    {
        std::cout << "LOAD::Enter" << std::endl;

        return 0;
    }

    int LoadPhase::InternOnRun()
    {
        std::cout << "LOAD::Run" << std::endl;

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
        std::cout << "LOAD::Leave" << std::endl;

        return 0;
    }
}
