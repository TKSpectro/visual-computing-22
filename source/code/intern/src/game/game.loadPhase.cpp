#include "game.loadPhase.h"
#include <iostream>

namespace Game
{
    int LoadPhase::InternOnEnter()
    {
        std::cout << "GAME::LOAD::Enter" << std::endl;

        return 0;
    }

    int LoadPhase::InternOnRun()
    {
        std::cout << "GAME::LOAD::Run" << std::endl;

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
        std::cout << "GAME::LOAD::Leave" << std::endl;

        return 0;
    }
}
